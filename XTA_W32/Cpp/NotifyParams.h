#pragma once

#include "XFinApiCommon.h"
#include <functional>
#include <utility>
#include <vector>

namespace XFinApi
{
	namespace TradeApi
	{
		// 通知代码数据
		struct CodeInfo
		{
			std::string Code;
			std::string LowerCode;
			std::string LowerMessage;

			CodeInfo()
			{
			}

#if !defined(SWIG)
			explicit CodeInfo(std::string code, std::string lowerCode = "", std::string lowerMsg = "")
				: Code(std::move(code))
				, LowerCode(std::move(lowerCode))
				, LowerMessage(std::move(lowerMsg))
			{
			}

			bool operator ==(const CodeInfo &other) const
			{
				return Code == other.Code &&
					LowerCode == other.LowerCode &&
					LowerMessage == other.LowerMessage;
			}

			struct Hasher
			{
				size_t operator ()(const CodeInfo &ci) const
				{
					std::hash<std::string> hashFunc;
					return hashFunc(ci.Code) ^ hashFunc(ci.LowerCode) ^ hashFunc(ci.LowerMessage);
				}
			};
#endif
		};

		// 通知数据
		struct NotifyParams
		{
			int ActionType = INT32_DEFAULT;
			int ResultType = INT32_DEFAULT;
			std::vector<CodeInfo> CodeInfos;

			void Clear()
			{
				ActionType = INT32_DEFAULT;
				ResultType = static_cast<int>(ResultKind::Failed);
				CodeInfos.clear();
			}

			bool IsSuccess() const
			{
				return ResultType == static_cast<int>(ResultKind::Success);
			}
		};
	}
}
