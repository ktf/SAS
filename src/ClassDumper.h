// Dumps class info
// Dumps class inheritance info

#ifndef Utilities_StaticAnalyzers_MemberDumper_h
#define Utilities_StaticAnalyzers_MemberDumper_h
#include <clang/AST/DeclCXX.h>
#include <clang/AST/Decl.h>
#include <clang/AST/DeclTemplate.h>
#include <clang/AST/StmtVisitor.h>
#include <clang/AST/ParentMap.h>
#include <clang/Analysis/CFGStmtMap.h>
#include <llvm/Support/SaveAndRestore.h>
#include <clang/StaticAnalyzer/Core/PathSensitive/AnalysisManager.h>
#include <clang/StaticAnalyzer/Core/Checker.h>
#include <clang/StaticAnalyzer/Core/BugReporter/BugReporter.h>
#include <clang/StaticAnalyzer/Core/BugReporter/BugType.h>
#include <llvm/ADT/SmallString.h>

#include "SasException.h"
#include "SasSupport.h"

namespace sas
{

   class ClassDumper : public clang::ento::Checker<clang::ento::check::ASTDecl<clang::CXXRecordDecl>>
   {
      mutable std::unique_ptr<clang::ento::BugType> BT;

    public:
      void checkASTDecl(const clang::CXXRecordDecl* CRD, clang::ento::AnalysisManager& mgr, clang::ento::BugReporter& BR) const;

    private:
      SasException m_exception;
   };

   // Dumps class info
   class ClassDumperCT : public clang::ento::Checker<clang::ento::check::ASTDecl<clang::ClassTemplateDecl>>
   {
      mutable std::unique_ptr<clang::ento::BugType> BT;

    public:
      void checkASTDecl(const clang::ClassTemplateDecl* TD, clang::ento::AnalysisManager& mgr, clang::ento::BugReporter& BR) const;

    private:
      SasException m_exception;
   };

   // Dumps class info
   class ClassDumperFT : public clang::ento::Checker<clang::ento::check::ASTDecl<clang::FunctionTemplateDecl>>
   {
      mutable std::unique_ptr<clang::ento::BugType> BT;

    public:
      void checkASTDecl(const clang::FunctionTemplateDecl* TD, clang::ento::AnalysisManager& mgr, clang::ento::BugReporter& BR) const;

    private:
      SasException m_exception;
   };

   // Dumps class inheritance info
   class ClassDumperInherit : public clang::ento::Checker<clang::ento::check::ASTDecl<clang::CXXRecordDecl>>
   {
      mutable std::unique_ptr<clang::ento::BugType> BT;

    public:
      void checkASTDecl(const clang::CXXRecordDecl* CRD, clang::ento::AnalysisManager& mgr, clang::ento::BugReporter& BR) const;

    private:
      SasException m_exception;
   };
}
#endif
