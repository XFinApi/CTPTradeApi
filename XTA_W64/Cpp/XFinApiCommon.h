#pragma once

#define NOMINMAX

#include <stdint.h>
#include <type_traits>
#include <limits>
#include <cmath>
#include <string>
#include <map>

#if defined(_DEBUG) && !defined(NDEBUG)
#define XFINAPI_VERSION_POSTFIX	".Debug"
#else
#define XFINAPI_VERSION_POSTFIX
#endif

#define XFINAPI_ITRADEAPI_VERSION	"XFinApi.TradeApi.180302" XFINAPI_VERSION_POSTFIX

#if !defined(XFINAPI)
# if defined(_MSC_VER)
#  if defined(TRADEAPI_EXPORT)
#   define XFINAPI __declspec(dllexport)
#  elif defined(TRADEAPI_LIB)
#   define XFINAPI
#  else
#   define XFINAPI __declspec(dllimport)
#  endif
# else
#  define XFINAPI __attribute__((visibility("default")))
# endif
#endif

#if defined(SWIG)
# define INT32_DEFAULT  0
# define INT64_DEFAULT  0
# define DOUBLE_DEFAULT 0
#else
# define INT32_DEFAULT	(std::numeric_limits<int32_t>::min)()
# define INT64_DEFAULT	(std::numeric_limits<int64_t>::min)()
# define DOUBLE_DEFAULT	std::numeric_limits<double>::quiet_NaN()
#endif

#if defined(RCDEV)
#define DEV_LOG(_fmt, ...) printf("[DevLog - %s] " _fmt "\n", __FUNCTION__, __VA_ARGS__)
#else
#define DEV_LOG(_fmt, ...)
#endif

#define VERIFY_FIELD_DEFAULT(_p, _field, _codeInfos) \
    do { \
        if (IsDefaultValue(_p._field)) \
        { \
            _codeInfos.emplace_back(ErrorCodeKind::Err##_field, "", ""); \
        } \
    } while (0)

#define VERIFY_CONFIG_DEFAULT(_p, _field, _codeInfos) \
    do { \
        auto _finded = _p.Configs.find(#_field); \
        if (_finded == _p.Configs.end() || IsDefaultValue(_finded->second)) \
        { \
            _codeInfos.emplace_back(ErrorCodeKind::Err##_field, "", ""); \
        } \
    } while (0)

#define VERIFY_LETTERNUMBER(_p, _field, _codeInfos)\
    do { \
        if (!Utils::VerifyLetterNumber(_p._field)) \
        { \
            _codeInfos.emplace_back(ErrorCodeKind::Err##_field, "", ""); \
        } \
    } while (0)

#define ASSIGN_MARGINRATE_FIELDS(_prefix, _lm, _lv, _sm, _sv) \
    do { \
        if (IsDefaultValue(inst._prefix##LongMarginRatioByMoney)) \
            inst._prefix##LongMarginRatioByMoney = _lm; \
        if (IsDefaultValue(inst._prefix##LongMarginRatioByVolume)) \
            inst._prefix##LongMarginRatioByVolume = _lv; \
        if (IsDefaultValue(inst._prefix##ShortMarginRatioByMoney)) \
            inst._prefix##ShortMarginRatioByMoney = _sm; \
        if (IsDefaultValue(inst._prefix##ShortMarginRatioByVolume)) \
            inst._prefix##ShortMarginRatioByVolume = _sv; \
    } while (0)

namespace XFinApi
{
namespace TradeApi
{
	inline bool IsDefaultValue(int32_t v)
	{
		return v == INT32_DEFAULT;
	}

	inline bool IsDefaultValue(int64_t v)
	{
		return v == INT64_DEFAULT;
	}

	inline bool IsDefaultValue(double v)
	{
		return std::isnan(v) ||
			v == (std::numeric_limits<double>::max)() ||
			v == (std::numeric_limits<double>::min)();
	}

    inline bool IsDefaultValue(const std::string &v)
    {
        return v.empty();
    }

#if !defined(SWIG)
    template <class T, class = typename std::enable_if<std::is_enum<T>::value>::type>
    bool IsDefaultValue(T e)
    {
        return e == T::Default;
    }
#endif
}
}
