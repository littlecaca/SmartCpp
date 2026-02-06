

#include "singleton.h"
#include <string>
#include <unordered_map>
#include <utility>
#include <functional>

/**
 * @pattern 工厂注册表模式 (Factory Registry Pattern)
 * -------------------------------------------------------------------------
 * @brief 功能 (Function):
 * 1. 插件化扩展：支持在不修改工厂类源代码的情况下，动态增加新的产品实现。
 * 2. 彻底解耦：消除传统简单工厂中臃肿的 switch-case 或 if-else 逻辑。
 * 3. 运行时绑定：支持根据配置字符串、RPC 参数或动态库加载情况实例化对象。
 *
 * @details 原理 (Mechanism):
 * 1. 映射机制：工厂内部维护一个注册表（通常为 std::unordered_map），
 * 将唯一标识符（Key/String）映射到创建函数（Factory Method/Lambda）。
 * 2. 静态触发：利用 C++ 全局静态变量在 main 执行前的初始化特性，
 * 通过静态实例的构造函数完成产品“自报到”。
 * 3. 闭环扩展：新增产品只需在自身的 .cpp 文件中使用注册宏，
 * 该文件被链接时，其符号即自动注入工厂注册表。
 *
 * @note 实现方法 (Implementation):
 * 1. [Registry]：单例工厂类，提供 Register(key, creator) 和 Create(key) 接口。
 * 2. [Registrar]：辅助工具类，构造函数执行 Register 逻辑。
 * 3. [Macro]：定义 REGISTER_PRODUCT(key, class) 宏，内部声明一个静态 Registrar 实例。
 * 4. [Linkage]：关键步骤！为防止链接器优化掉未被显式引用的 .o 文件，
 * 必须使用 --whole-archive (Linux) 或 alwayslink=1 (Bazel) 强制符号驻留。
 * -------------------------------------------------------------------------
 */
class BaseProduct {

};

class FactoryRegistery : Singleton<FactoryRegistery> {
public:
  using Creator = std::function<BaseProduct *()>;

private:
  std::unordered_map<std::string, Creator> creators_;

};
