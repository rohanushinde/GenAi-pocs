import UIKit
 
class ViewController: UIViewController {
    override func viewDidLoad() {
        super.viewDidLoad()
        // Deprecated API: UIWebView
        let webView = UIWebView(frame: view.bounds)
        view.addSubview(webView)
        // Load a webpage
        if let url = URL(string: "https://www.example.com") {
            let request = URLRequest(url: url)
            webView.loadRequest(request)
        }
    }
}