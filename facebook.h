#ifndef FACEBOOK_H
#define FACEBOOK_H

#include <QObject>
#include <QUrl>

namespace nsFacebook {

/**
 * @brief The Facebook class
 *
 * Singleton class for handling various facebook operations
 * It also stores the attributes like client id, client secret and access token.
 */
class Facebook : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief InitializeFacebook
     * Initializes facebook singleton with client id and secret
     *
     * @param clientId        Client Id of facebook app
     * @param clientSecret    Client Secret of facebook app
     * @return Initialized and returns an object of facebook singleton
     */
    static Facebook* InitializeFacebook(QString clientId, QString clientSecret);

    /**
     * @brief Instance
     * @return An object of facebook singleton which has already been initialized
     *
     * Note:-
     * Only call this when InitializeFacebook() has been called,
     * otherwise you will get an null pointer exception.
     * (My bad design !)
     */
    static Facebook* Instance();

    void ParseLoginResponse(QString jsonStr);

    //-----------------------------------------------
    //  Getters
    //-----------------------------------------------
    QString ClientId();
    QString ClientSecret();
    QString AccessToken();
    QUrl OAuthUrl();
    QUrl AccessTokenUrl();

    //-----------------------------------------------
    //  Setters
    //-----------------------------------------------
    void SetAccessCode(QString code);
    void SetAccessToken(QString accessToken);



signals:

public slots:


private:
    /**
     * @brief Facebook
     * Private constructor of singleton, to be called by InitializeFacebook()
     *
     * @param parent            Parent QObject
     * @param clientId          Client Id of facebook app
     * @param clientSecret      Client Secret of facebook app
     */
    explicit Facebook(QString clientId, QString clientSecret, QObject *parent = 0);


private:
    QString clientId;
    QString clientSecret;
    QString accessToken;

    QString accessCode;
    QString accessTokenUrl;\
    QString oauthUrl;
};


//--------------------------------------------------
// Convenience MACRO wrapper functions/shoortcuts
//--------------------------------------------------
#define FB_CLIENT_ID                Facebook::Instance()->ClientId()
#define FB_CLIENT_SECRET            Facebook::Instance()->ClientSecret()
#define FB_OAUTH_URL                Facebook::Instance()->OAuthUrl()
#define FB_SET_ACCESS_CODE(code)    Facebook::Instance()->SetAccessCode(code)
#define FB_ACCESS_TOKEN_URL         Facebook::Instance()->AccessTokenUrl()
#define FB_ACCESS_TOKEN             Facebook::Instance()->AccessToken()
#define FB_SUCCESS_URL              QString("https://www.facebook.com/connect/login_success.html")
}// nsFacebook

#endif // FACEBOOK_H


