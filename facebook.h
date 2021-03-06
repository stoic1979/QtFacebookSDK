/*
 *  This file is part of SocialDashboard.
 *
 *  SocialDashboard is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  SocialDashboard is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with SocialDashboard.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *  ------------------------------------------------------------------------------
 *     About: This SDK is under development by Weavebytes Infotech Pvt Ltd, India
 *    Author: Navjot Singh
 *   Website: www.weavebytes.com
 *  ------------------------------------------------------------------------------
 */

#ifndef FACEBOOK_H
#define FACEBOOK_H

#include <QObject>
#include <QUrl>

#include <QNetworkRequest>
#include <QNetworkReply>

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
     * @return                An Initialized object of facebook singleton
     */
    static Facebook* Initialize(QString clientId, QString clientSecret);

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

    void GetAccessToken(QUrl url);
    void GetUserId();
    void GetFriendList();

    void ParseLoginResponse(QString jsonStr);
    void ParseUserIdResponse(QString jsonStr);

    //-----------------------------------------------
    //  Getters
    //-----------------------------------------------
    QString ClientId();
    QString ClientSecret();
    QString AccessToken();
    QUrl OAuthUrl();
    QUrl AccessTokenUrl();
    QString UserId();
    QString Username();

    //-----------------------------------------------
    //  Setters
    //-----------------------------------------------
    void SetAccessCode(QString code);
    void SetAccessToken(QString accessToken);

signals:
    void GotFacebookAccessToken(bool error, QString jsonStr);


public slots:   
    void ReplyForAccessToken(QNetworkReply *reply);
    void ReplyForUserId(QNetworkReply *reply);
    void ReplyForFriendList(QNetworkReply* reply);

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

    QString userId;
    QString userName;
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
#define FB                          Facebook::Instance()
#define FB_USER_ID                  Facebook::Instance()->UserId()
#define FB_USER_NAME                Facebook::Instance()->Username()
}// nsFacebook

#endif // FACEBOOK_H
