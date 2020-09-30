//
//  TESDK.h
//  TemSDK
//
//  Created by iOS王艺博 on 2019/8/30.
//  Copyright © 2019 iOS王艺博. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef void (^callBackBlock)(BOOL isSuccess, NSDictionary * _Nonnull result);
typedef NS_ENUM(NSInteger,NSUPRoleInfo){
    NSUPRoleInfoRoleEnter = 0,  //进入游戏
    NSUPRoleInfoRoleCreat,      //创建角色
    NSUPRoleInfoRoleUpLevel,    //升级角色
    NSUPRoleInfoRoleOnline      //角色online
};
NS_ASSUME_NONNULL_BEGIN

@interface TESDK : NSObject

@property (nonatomic , assign)BOOL teSDKisShowBuoy; //是否展示小助手，默认展示，该设置需在登录后

+(instancetype)shared; //单例
//游戏初始化
+(void)teSdk_initWithGameId:(NSString *)gameId gamePkg:(NSString *)gamePkg;
//登录 ,state 是否自动登录
+(void)teSdk_loginWithState:(BOOL)state;
//注销/登出
+(void)teSdk_logOut;

/**
 product （所有字段不能为空，如果没有相关参数，请传入 1 ）

 @param proId 商品id
 @param appleId 苹果商品id
 @param proName 商品名称
 @param proDesc 商品描述
 @param price 商品价格 - 字符串类型
 @param roleId 角色id
 @param roleName 角色名称
 @param roleLev 角色等级
 @param cpOrder cp订单号
 @param extension 拓展字段
 @param serveId 服务器id
 @param serveName 服务器名称
 */
+(void)teSdk_productWithProId:(NSString*)proId appleId:(NSString*)appleId ProName:(NSString*)proName proDesc:(NSString*)proDesc price:(NSString*)price roleId:(NSString*)roleId roleName:(NSString*)roleName roleLev:(NSString*)roleLev cpOrder:(NSString*)cpOrder extension:(NSString*)extension serveId:(NSString*)serveId serveName:(NSString*)serveName;

/**
 日志上报接口
 
 @param type 上报类型，请参照NSUPRoleInfo枚举
 @param roleID 角色id
 @param roleLev 角色等级
 @param roleName 角色名
 @param serverId 服务器id
 @param serverName 服务器name
 @param block 日志上报回调
 */
+(void)teSdk_sendGameDataWithType:(NSUPRoleInfo)type roleID:(NSString*)roleID roleLev:(NSString*)roleLev roleName:(NSString*)roleName serverId:(NSString*)serverId serverName:(NSString*)serverName block:(callBackBlock)block;

#pragma mark - 回调
-(void)teSdk_initCallBackBlock:(callBackBlock)initBlock;

-(void)teSdk_loginCallBackBlock:(callBackBlock)loginBlock;

-(void)teSdk_logoutCallBackBlock:(callBackBlock)logoutBlock;

-(void)teSdk_productInfoCallBackBlock:(callBackBlock)proBlock;
#pragma mark - 生命周期


@end

NS_ASSUME_NONNULL_END
