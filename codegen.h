#pragma once

#include <ast/l.h>

#include <llvm/IR/Module.h>

#include <memory>
#include <unordered_set>
#include <unordered_map>

namespace codegen
{
std::unique_ptr<llvm::Module> generate(const ast::Code & code);

struct context
{
    std::unordered_map<std::string, llvm::Value *> variables;
    std::unordered_map<std::string, llvm::Function *> functions;
};

void gen_entry(const ast::Declaration & entry);
void gen_entry(const ast::Definition & entry);
void gen_entry(const ast::VarDeclaration & entry);
void gen_entry(const ast::FuncDefinition & entry);
void gen_entry(const ast::FuncDeclaration & entry);

llvm::Value * gen_expr(const context & ctx, int64_t i);
llvm::Value * gen_expr(const context & ctx, bool b);
llvm::Value * gen_expr(const context & ctx, const ast::Const & v);
llvm::Value * gen_expr(const context & ctx, const std::string & v);
llvm::Value * gen_expr(const context & ctx, const ast::Value & v);
llvm::Value * gen_expr(const context & ctx, const ast::BinOperator & op);
llvm::Value * gen_expr(const context & ctx, const ast::Dereference & deref);
llvm::Value * gen_expr(const context & ctx, const ast::Call & call);
llvm::Value * gen_expr(const context & ctx, const ast::Expression & expr);

context gen_statement(const context & ctx, const ast::Skip & st);
context gen_statement(const context & ctx, const ast::VarDeclaration & st);
context gen_statement(const context & ctx, const ast::Statement & st);
}