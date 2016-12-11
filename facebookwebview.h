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
