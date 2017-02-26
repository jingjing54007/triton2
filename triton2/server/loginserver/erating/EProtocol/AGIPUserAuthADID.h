#ifndef __AGIP_USER_AUTH_AD_ID_H__
#define __AGIP_USER_AUTH_AD_ID_H__

#include "SysProtocol.h"

#define CMD_USER_AUTH_AD_ID                  0x10003305
#define CMD_USER_AUTH_AD_ID_RES              0x20003305

const int32_t AGIP_AD_ID_LENGTH     = 32;

typedef struct _AGIP_USER_AUTH_AD_ID_
{
    _AGIP_HEADER_   header;
    uint16_t        us_Game_Id;
    uint16_t        pad;
    uint32_t        un_Gateway_Id;
    char            str_User_Name[AGIP_USER_NAME_LEN];
    char            str_Password[AGIP_PASSWORD_LEN];
    int8_t          c_Password_Type;
    int8_t          pad_2;
    uint16_t        us_User_Port;
    uint32_t        un_User_IP;
    char            str_Matrix_Password[AGIP_PASSWORD_LEN];
    char            str_Matrix_Coord[AGIP_MATRIX_COORD_LEN];
    char            sz_MAC[AGIP_MAC_LEN];
    char            sz_AD_ID[AGIP_AD_ID_LENGTH];
    _AGIP_CHECKSUM_ checksum;
} SAGIPUserAuthADID, *PSAGIPUserAuthADID;

typedef struct _AGIP_USER_AUTH_AD_ID_RES_
{
    _AGIP_HEADER_   header;
    int32_t         n_Result_Code;
    uint32_t        un_User_ID;
    int8_t          c_User_Type;
    int8_t          c_Adult_Flag;
    int8_t          c_User_Class;
    int8_t          pad;
    int32_t         n_User_Point;
    uint32_t        un_Promoter_ID;
    uint32_t        un_User_Flag;
    _AGIP_CHECKSUM_ checksum;
} SAGIPUserAuthADIDRes, *PSAGIPUserAuthADIDRes;


class Engine_Export AGIPUserAuthADID :
    public SysProtocol
{
public:
    enum
    {
        PASSWORD_TYPE_AUTHENTICATION = 1,
        PASSWORD_TYPE_SECURITY       = 2,
        PASSWORD_TYPE_MATRIX
    };

    AGIPUserAuthADID(void);

    int getUserName(char *strUserName);
    int getPassword(char *strPassword);
    int getPasswordType(int8_t *pcPasswordType);
    int getUserPort(uint16_t *pusUserPort);
    int getUserIP(uint32_t *punUserIP);
    int getMatrixPassword(char* szMatrixPassword);
    int getMatrixCoord(char* szMatrixCoord);
    int getGameID(uint16_t* pucGameID);
    int getGatewayID(uint32_t* punGatewayID);
    int getMAC(char *strMAC);
    const char* getADID(char* szADID, size_t unSize);

    int setUserName(const char *strUserName);
    int setPassword(const char *strPassword);
    int setPasswordType(int8_t cPasswordType);
    int setUserPort(uint16_t usUserPort);
    int setUserIP(uint32_t unUserIP);
    int setMatrixPassword(const char* szMatrixPassword);
    int setMatrixCoord(const char* szMatrixCoord);
    int setGameID(uint16_t usGameID);
    int setGatewayID(uint32_t unGatewayID);
    int setMAC(const char* szMAC);
    int setADID(const char *szADID);

    virtual int showInfo();

public:
    virtual ~AGIPUserAuthADID(void);
};

class Engine_Export AGIPUserAuthADIDRes :
    public SysProtocol
{
public:
    AGIPUserAuthADIDRes(void);
    virtual ~AGIPUserAuthADIDRes(void);

    int getResultCode(int32_t *pnResultCode);
    int getUserID(uint32_t *punUserID);
    int getUserType(int8_t *pcUserType);
    int getAdultFlag(int8_t *pcAdultFlag);
    int getUserClass(int8_t *pcUserClass);
    int getUserPoint(int32_t *pnUserPoint);
    int getPromoterID(uint32_t *punPromoterID);
    int getUserFlag(uint32_t *punUserFlag);

    int setResultCode(int32_t nResultCode);
    int setUserID(uint32_t unUserID);
    int setUserType(int8_t cUserType);
    int setAdultFlag(int8_t cAdultFlag);
    int setUserClass(int8_t cUserClass);
    int setUserPoint(int32_t nUserPoint);
    int setPromoterID(uint32_t unPromoterID);
    int setUserFlag(uint32_t unUserFlag);

    virtual int showInfo();
};

#endif