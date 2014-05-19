/*!
 @header EMMessage.h
 @abstract 聊天消息对象类型
 @author EaseMob Inc.
 @version 1.00 2014/01/01 Creation (1.00)
 */

#import <Foundation/Foundation.h>
#import "EMMessageBody.h"

@class EMConversation;

/*!
 @class
 @abstract 聊天消息类
 */
@interface EMMessage : NSObject

/*!
 @property
 @abstract 消息来源用户名
 */
@property (nonatomic, copy) NSString *from; // should be username for now

/*!
 @property
 @abstract 消息目的地用户名
 */
@property (nonatomic, copy) NSString *to;   // should be username for now

/*!
 @property
 @abstract 消息ID
 */
@property (nonatomic, copy) NSString *messageId;

/*!
 @property
 @abstract 消息在发送前是否需要加密
 */
@property (nonatomic) BOOL requireEncryption;

/*!
 @property
 @abstract 消息发送或接收的时间
 */
@property (nonatomic) long long timestamp;

/*!
 @property
 @abstract 消息是否已读
 */
@property (nonatomic) BOOL isRead;

/*!
 @property
 @abstract 是否接收到了接收方的阅读回执, 或是否已发送了阅读回执给对方
 @discussion 针对发送的消息, 当接收方读了消息后, 会发回已读回执, 接收到了已读回执, 此标记位会被置为YES; 
             针对接收的消息, 发送了阅读回执后, 此标记会被置为YES
 */
@property (nonatomic) BOOL isAcked;

/*!
 @property
 @abstract 消息体列表
 */
@property (nonatomic, strong) NSArray *messageBodies;

/*!
 @property
 @abstract 消息所属的对话对象
 */
@property (nonatomic, weak) EMConversation *conversation;

/*!
 @property
 @abstract 此消息是否是群聊消息
 */
@property (nonatomic) BOOL isChatroom;

/*!
 @property
 @abstract 群聊消息里的发送者用户名
 */
@property (nonatomic, copy) NSString *chatroomSenderName;

/*!
 @property
 @abstract 消息扩展
 */
@property (nonatomic, strong) NSDictionary *ext;

/*!
 @property
 @abstract 消息送达状态
 */
@property (nonatomic) MessageDeliveryState deliveryState;

/*!
 @method
 @abstract 创建消息实例
 @discussion 消息实例会在发送过程中内部状态发生更改,比如deliveryState
 @param receiver 消息接收方
 @param bodies 消息体列表
 @result 消息实例
 */
- (id)initWithReceiver:(NSString *)receiver
               bodies:(NSArray *)bodies;

/*!
 @method
 @abstract 将消息体加入消息实例
 @discussion 消息实例可以对消息体进行动态的添加删除
 @param body 消息体
 @result 此消息的消息体列表
 */
- (NSArray *)addMessageBody:(EMMessageBody *)body;

/*!
 @method
 @abstract 将消息体从消息实例中移除
 @discussion 消息实例可以对消息体进行动态的添加删除
 @param body 消息体
 @result 此消息的消息体列表
 */
- (NSArray *)removeMessageBody:(EMMessageBody *)body;

@end