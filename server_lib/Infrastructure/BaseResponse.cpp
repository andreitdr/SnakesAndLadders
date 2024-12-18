#include "BaseResponse.h"

BaseResponse::BaseResponse(const bool bSuccess) : m_bSuccess{bSuccess}
{
    // Empty constructor
}
BaseResponse::BaseResponse(const std::string& strContent) :
                m_strMessage{strContent}, m_bSuccess{false}
{
    // Empty constructor
}

BaseResponse::operator bool() const {
    return m_bSuccess;
}


bool BaseResponse::getSuccess() const {
    return m_bSuccess;
}

const std::string& BaseResponse::getMessage() const {
    return m_strMessage;
}
