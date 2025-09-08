/**
 * FATAppletH5WebviewDelegate
 * 用于宿主APP处理WebView相关的导航、加载和策略决策的代理协议
 *
 * 所有代理方法的返回值说明：
 * 返回值  BOOL - 返回YES表示宿主APP已处理该事件，SDK不会执行内部处理逻辑；
 *               返回NO表示宿主APP未处理该事件，SDK会执行默认的内部处理逻辑
 */
@protocol FATAppletH5WebviewDelegate <NSObject>

@optional

/// 小程序webview组件即将加载url，可以在这里通过userContentController注入js代码
/// - Parameters:
///   - appletInfo: 小程序信息
///   - webview: webview对象
///   - urlString: 即将加载的url
///   - userContentController: WKUserContentController，可以注入js
- (void)applet:(FATAppletInfo *)appletInfo webview:(WKWebView *)webview WillLoadURL:(NSString *)urlString withUserContentController:(WKUserContentController *)userContentController;


/**
 * WebView导航失败时调用
 * @param webView 当前的WebView实例
 * @param navigation 失败的导航对象
 * @param error 导航失败的错误信息
 */
- (BOOL)fat_webView:(WKWebView *)webView didFailNavigation:(WKNavigation *)navigation withError:(NSError *)error;

/**
 * WebView导航完成时调用
 * @param webView 当前的WebView实例
 * @param navigation 完成的导航对象
 */
- (BOOL)fat_webView:(WKWebView *)webView didFinishNavigation:(WKNavigation *)navigation;

/**
 * WebView预加载导航失败时调用
 * @param webView 当前的WebView实例
 * @param navigation 失败的预加载导航对象
 * @param error 导航失败的错误信息
 */
- (BOOL)fat_webView:(WKWebView *)webView didFailProvisionalNavigation:(WKNavigation *)navigation withError:(NSError *)error;

/**
 * WebView收到服务器重定向时调用
 * @param webView 当前的WebView实例
 * @param navigation 被重定向的导航对象
 */
- (BOOL)fat_webView:(WKWebView *)webView didReceiveServerRedirectForProvisionalNavigation:(null_unspecified WKNavigation *)navigation;

/**
 * WebView开始预加载导航时调用
 * @param webView 当前的WebView实例
 * @param navigation 开始的预加载导航对象
 */
- (BOOL)fat_webView:(WKWebView *)webView didStartProvisionalNavigation:(null_unspecified WKNavigation *)navigation;

/**
 * 决定WebView是否接受导航响应
 * @param webView 当前的WebView实例
 * @param navigationResponse 导航响应对象
 * @param decisionHandler 决策处理回调，传入WKNavigationResponsePolicy值
 */
- (BOOL)fat_webView:(WKWebView *)webView decidePolicyForNavigationResponse:(WKNavigationResponse *)navigationResponse decisionHandler:(void (^)(WKNavigationResponsePolicy))decisionHandler;

/**
 * 决定WebView是否允许导航操作
 * @param webView 当前的WebView实例
 * @param navigationAction 导航操作对象
 * @param decisionHandler 决策处理回调，传入WKNavigationActionPolicy值
 */
- (BOOL)fat_webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler;

/**
 * 决定WebView是否允许导航操作并可配置页面首选项
 * @param webView 当前的WebView实例
 * @param navigationAction 导航操作对象
 * @param preferences 网页首选项配置
 * @param decisionHandler 决策处理回调，传入WKNavigationActionPolicy值和更新后的WKWebpagePreferences
 */
- (BOOL)fat_webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction preferences:(WKWebpagePreferences *)preferences decisionHandler:(void (^)(WKNavigationActionPolicy, WKWebpagePreferences *))decisionHandler;

/**
 * 为打开新窗口的请求创建新的WebView
 * @param webView 当前的WebView实例
 * @param configuration 新WebView的配置
 * @param navigationAction 触发创建新窗口的导航操作
 * @param windowFeatures 新窗口的特性
 * @return 返回新创建的WebView或nil（如不支持新窗口）
 */
- (nullable WKWebView *)fat_webView:(WKWebView *)webView createWebViewWithConfiguration:(WKWebViewConfiguration *)configuration forNavigationAction:(WKNavigationAction *)navigationAction windowFeatures:(WKWindowFeatures *)windowFeatures;

/**
 * 显示JavaScript文本输入面板（prompt）
 * @param webView 当前的WebView实例
 * @param prompt 提示信息
 * @param defaultText 默认文本
 * @param frame 发起请求的框架信息
 * @param completionHandler 完成回调，传入用户输入的文本或nil
 */
- (BOOL)fat_webView:(WKWebView *)webView runJavaScriptTextInputPanelWithPrompt:(NSString *)prompt defaultText:(nullable NSString *)defaultText initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(NSString *_Nullable result))completionHandler;

/**
 * 显示JavaScript警告面板（alert）
 * @param webView 当前的WebView实例
 * @param message 警告信息
 * @param frame 发起请求的框架信息
 * @param completionHandler 完成回调
 */
- (BOOL)fat_webView:(WKWebView *)webView runJavaScriptAlertPanelWithMessage:(NSString *)message initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(void))completionHandler;

/**
 * 显示JavaScript确认面板（confirm）
 * @param webView 当前的WebView实例
 * @param message 确认信息
 * @param frame 发起请求的框架信息
 * @param completionHandler 完成回调，传入用户选择（确认为YES，取消为NO）
 */
- (BOOL)fat_webView:(WKWebView *)webView runJavaScriptConfirmPanelWithMessage:(NSString *)message initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(BOOL))completionHandler;

@end
