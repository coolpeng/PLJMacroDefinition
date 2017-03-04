//
//  Macro.h
//  PLJMacroDefinition
//
//  Created by Edward on 17/3/4.
//  Copyright © 2017年 coolpeng. All rights reserved.
//

#ifndef Macro_h
#define Macro_h

// 1. APP版本号
#define AppVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

// 2. 尺寸相关
/*屏幕*/
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height
#define SCREEN_SIZE [UIScreen mainScreen].bounds.size
#define NAV_BAR_HEIGHT   44
#define STATUS_BAR_HEIGHT   20
#define STATUS_AND_NAV_HEIGHT 64

// 3. 颜色相关
/*随机颜色*/
#define RandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]

/*RGB颜色/RGBA颜色*/
#define RGBColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define RGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]
#define RGBAHex(rgbValue,a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:a]


#define Application [UIApplication sharedApplication]
#define KeyWindow [UIApplication sharedApplication].keyWindow
#define AppDelegate [UIApplication sharedApplication].delegate
#define NSUserDefaults [NSUserDefaults standardUserDefaults]
#define NotificationCenter [NSNotificationCenter defaultCenter]


// 4. 打印功能
#ifdef DEBUG
#define Log(...) NSLog(@"%s 第%d行 \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define Log(...)

#endif

// 5. 弱引用/强引用
#define WeakSelf(type)  __weak typeof(type) weak##type = type;
#define StrongSelf(type)  __strong typeof(type) type = weak##type;

// 6. 获取图片资源
#define GetImage(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]

// 7. 获取当前语言
#define CurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

// 8. 手机型号
/* iPhone 5SE */
#define iPhone5SE [[UIScreen mainScreen] bounds].size.width == 320.0f && [[UIScreen mainScreen] bounds].size.height == 568.0f

/* iPhone 6/6s */
#define iPhone6_6s [[UIScreen mainScreen] bounds].size.width == 375.0f && [[UIScreen mainScreen] bounds].size.height == 667.0f

/* iPhone 6Plus/6sPlus */
#define iPhone6Plus_6sPlus [[UIScreen mainScreen] bounds].size.width == 414.0f && [[UIScreen mainScreen] bounds].size.height == 736.0f

// 9. 沙盒目录文件
/*获取temp*/
#define PathTemp NSTemporaryDirectory()

/*获取沙盒 Document*/
#define PathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]

/*获取沙盒 Cache*/
#define PathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

// 10. GCD 的宏定义
/* 一次性执行 */
#define DISPATCH_ONCE_BLOCK(onceBlock) static dispatch_once_t onceToken; dispatch_once(&onceToken, onceBlock);

/* 在Main线程上运行 */
#define DISPATCH_MAIN_THREAD(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);

/* 开启异步线程 */
#define DISPATCH_GLOBAL_QUEUE_DEFAULT(globalQueueBlock) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlock);


#endif /* Macro_h */
