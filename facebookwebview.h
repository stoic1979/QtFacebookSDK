/*
 *  This file is part of QtFacebookSDK.
 *
 *  QtFacebookSDK is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  QtFacebookSDK is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with QtFacebookSDK.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *  ------------------------------------------------------------------------------
 *     About: This SDK is under development by Weavebytes Infotech Pvt Ltd, India
 *    Author: Navjot Singh
 *   Website: www.weavebytes.com
 *  ------------------------------------------------------------------------------
 */

#ifndef FACEBOOKWEBVIEW_H
#define FACEBOOKWEBVIEW_H

#include <QWebEngineView>
#include <QWidget>
#include <QNetworkRequest>
#include <QNetworkReply>


namespace nsFacebook {

/**
 * @brief The FacebookWebView class
 *
 * This class handles facebook login and fetching of access token via a web view
 *
 *
 *   -----------------------------------------------------------------------------------------------
 *
 *       Facebook oauth Login
 *
 *       Refer Docs at:
 *       https://developers.facebook.com/docs/facebook-login/manually-build-a-login-flow/
 *
 *   -------------------------------------------------------------------------------------------------
 *
 *
 *  Invoking the Login Dialog and Setting the Redirect URL
 *
 *  Your app must initiate a redirect to an endpoint which will display the login dialog:
 *
 *  https://www.facebook.com/v2.8/dialog/oauth?client_id={app-id}&redirect_uri={redirect-uri}
 *
 *  This endpoint has the following required parameters:
 *
 *   - client_id:
 *     The ID of your app, found in your app's dashboard.
 *
 *   - redirect_uri:
 *     The URL that you want to redirect the person logging in back to.
 *     This URL will capture the response from the Login Dialog.
 *
 *     If you are using this in a webview within a desktop app,
 *     this must be set to https://www.facebook.com/connect/login_success.html.
 *     You can confirm that this URL is set for your app by going to the App Dashboard,
 *     clicking Facebook Login in the right-hand menu, and checking the Valid OAuth redirect
 *     URIs in the Client OAuth Settings section.
 *
 */
class FacebookWebView : public QWebEngineView
{
    Q_OBJECT
public:
    FacebookWebView(QWidget *parent);

    void LoginAndGetAccessToken();

signals:
   void GotFacebookAccessToken(bool error, QString jsonStr);

private:
    void GetFacebookAccessToken(QUrl url);

private slots:
    void WebViewUrlChanged(const QUrl& url);
    void ReplyFinished(QNetworkReply *reply);

private:
    // pass
};

}//nsFacebook

#endif // FACEBOOKWEBVIEW_H
