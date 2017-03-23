//
//  Macro.h
//  PLJMacroDefinition
//
//  Created by Edward on 17/3/4.
//  Copyright © 2017年 coolpeng. All rights reserved.
//

#ifndef Macro_h
#define Macro_h

// 应用程序的名字
#define kAppDisplayName  [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleDisplayName"]
// APP全版本号
#define kAppVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
// 系统版本号
#define kSystemVersion [[UIDevice currentDevice] systemVersion]

// 获取当前语言
#define kCurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

// 判断是否为iPhone
#define kISiPhone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
// 判断是否为iPad
#define kISiPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

// 手机型号
/* iPhone 5SE */
#define kiPhone_5SE [[UIScreen mainScreen] bounds].size.width == 320.0f && [[UIScreen mainScreen] bounds].size.height == 568.0f
/* iPhone 6/6s */
#define kiPhone6_6s [[UIScreen mainScreen] bounds].size.width == 375.0f && [[UIScreen mainScreen] bounds].size.height == 667.0f
/* iPhone 6Plus/6sPlus */
#define kiPhone6Plus_6sPlus [[UIScreen mainScreen] bounds].size.width == 414.0f && [[UIScreen mainScreen] bounds].size.height == 736.0f

// 尺寸相关
#define kScreenWidth      [UIScreen mainScreen].bounds.size.width
#define kScreenHeight     [UIScreen mainScreen].bounds.size.height
#define kScreenSize       [UIScreen mainScreen].bounds.size
#define kStatusBarHeight  (20.f)
#define kNavBarHeight     (64.f)
#define kStatusBarHeight  (20.f)
#define kTabBarHeight     (49.f)


// View Frame 相关宏定义
#define X(v)           (v).frame.origin.x
#define Y(v)           (v).frame.origin.y
#define kWidth(v)      (v).frame.size.width
#define kHeight(v)     (v).frame.size.height

#define kMinX(v)       CGRectGetMinX((v).frame) // 获得控件屏幕的x坐标(view.left)
#define kMinY(v)       CGRectGetMinY((v).frame) // 获得控件屏幕的Y坐标(view.top)
#define kMidX(v)       CGRectGetMidX((v).frame) //横坐标加上到控件中点坐标(view.center.x)
#define kMidY(v)       CGRectGetMidY((v).frame) //纵坐标加上到控件中点坐标(view.center.y)
#define kMaxX(v)       CGRectGetMaxX((v).frame) //横坐标加上控件的宽度(view.right)
#define kMaxY(v)       CGRectGetMaxY((v).frame) //纵坐标加上控件的高度(view.bottom)
#define kCenter(v)     CGPointMake(WIDTH(v)/2.0, HEIGHT(v)/2.0)  //视图的中心坐标

// 颜色相关
/*随机颜色*/
#define kRandomColor           [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]
/*RGB颜色/RGBA颜色*/
#define kRGBColor(r, g, b)     [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define kRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]
#define kRGBAHex(rgbValue,a)   [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:a]

// 一些系统单例
#define kApplication         [UIApplication sharedApplication]
#define kKeyWindow           [UIApplication sharedApplication].keyWindow
#define kAppDelegate         [UIApplication sharedApplication].delegate
#define kUserDefaults        [NSUserDefaults standardUserDefaults]
#define kNotificationCenter  [NSNotificationCenter defaultCenter]


// 打印功能
#ifdef DEBUG
#define Log(...) NSLog(@"%s 第%d行 \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define Log(...)

#endif

// 弱引用/强引用
#define kWeakSelf(type)  __weak typeof(type) weak##type = type;
#define kStrongSelf(type)  __strong typeof(type) type = weak##type;

//获取图片资源
#define kImageName(imageName)        [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]
#define kPNGImageName(imageName)     [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(imageName) ofType:@"png"]]
#define kJPGImageName(imageName)     [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(imageName) ofType:@"jpg"]]
#define kEXTImageName(imageName,EXT) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:(imageName) ofType:(EXT)]]

// 沙盒目录文件
/*获取沙盒 Document*/
#define kPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
/*获取temp*/
#define kPathTemp NSTemporaryDirectory()
/*获取沙盒 Cache*/
#define kPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

// GCD 的宏定义
/* 一次性执行 */
#define DISPATCH_ONCE_BLOCK(onceBlock) static dispatch_once_t onceToken; dispatch_once(&onceToken, onceBlock);
/* 在Main线程上运行 */
#define DISPATCH_MAIN_THREAD(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);
/* 开启异步线程 */
#define DISPATCH_GLOBAL_QUEUE_DEFAULT(globalQueueBlock) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlock);

// 判断是真机还是模拟器
#if TARGET_OS_IPHONE
// 真机
#endif

#if TARGET_IPHONE_SIMULATOR
// 模拟器
#endif

// 由角度转换弧度
#define kDegreesToRadian(x)      (M_PI * (x) / 180.0)
// 由弧度转换角度
#define kRadianToDegrees(radian) (radian * 180.0) / (M_PI)

// 获取一段时间间隔
#define kStartTime CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define kEndTime   NSLog(@"Time: %f", CFAbsoluteTimeGetCurrent() - start)


#endif /* Macro_h */
