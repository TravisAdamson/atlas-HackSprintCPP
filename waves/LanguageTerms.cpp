#include "LanguageTerms.h"

#include "LanguageTerms.h"

const QStringList CPlusPlusTerms = {
    "char", "float", "double", "short", "long", "long long",
    "unsigned int", "unsigned short", "unsigned long", "unsigned long long",
    "long double", "array", "pointer", "reference", "function",
    "struct", "union", "enum", "typedef", "class", "bool", "int",
    "const", "volatile", "static", "extern", "inline", "template",
    "namespace", "public", "protected", "private", "friend", "virtual",
    "override", "final", "dynamic_cast", "static_cast", "const_cast", "reinterpret_cast",
    "operator", "new", "delete", "this", "typeid", "sizeof", "decltype"
};

const QStringList PythonTerms = {
    "int", "float", "str", "list", "tuple", "dict", "set", "bool", "bytes", "bytearray",
    "None", "if", "else", "elif", "for", "while", "break", "continue", "pass", "return",
    "def", "class", "import", "from", "as", "with", "try", "except", "finally", "raise",
    "lambda", "map", "filter", "reduce", "list comprehension", "generator expression", "yield",
    "open", "close", "read", "write", "append", "seek", "format", "f-string", "print",
    "type", "isinstance", "issubclass", "staticmethod", "classmethod"
};

const QStringList BashTerms = {
    "echo", "printf", "cat", "grep", "awk", "sed", "cut", "sort", "uniq", "find",
    "locate", "xargs", "head", "tail", "chmod", "chown", "ln", "cp", "mv", "rm",
    "touch", "mkdir", "rmdir", "ls", "pwd", "cd", "bash", "sh", "source", "export",
    "unset", "alias", "unalias", "history", "jobs", "fg", "bg", "kill", "ps", "top",
    "ps aux", "tar", "gzip", "gunzip", "zip", "unzip", "wget", "curl", "sed -e", "awk '{print $1}'",
    "if", "then", "else", "elif", "fi", "for", "in", "do", "done", "while", "until",
    "case", "esac", "function", "return", "local", "getopts", "shift", "test", "[", "]"
};

const QStringList JavaTerms = {
    "int", "float", "double", "char", "byte", "short", "long", "boolean", "String", "array",
    "class", "interface", "enum", "abstract", "final", "static", "public", "private", "protected", "void",
    "new", "this", "super", "extends", "implements", "instanceof", "throws", "throw", "try",
    "catch", "finally", "assert", "synchronized", "volatile", "transient", "default", "constructor", "destructor",
    "method", "field", "variable", "package", "import", "main", "return", "break",
    "continue", "if", "else", "switch", "case", "default", "for", "while", "do"
};

const QStringList JavaScriptTerms = {
    "var", "let", "const", "function", "return", "if", "else", "switch", "case", "default",
    "for", "while", "do", "break", "continue", "try", "catch", "finally", "throw", "async",
    "await", "class", "extends", "constructor", "super", "static", "import", "export", "module", "default",
    "this", "prototype", "new", "delete", "typeof", "instanceof", "void", "null", "undefined", "NaN",
    "Infinity", "Promise", "fetch", "map", "filter", "reduce", "concat", "slice", "splice", "push",
    "pop", "shift", "unshift", "toString", "valueOf", "JSON", "Object", "Array", "String", "Number", "Boolean"
};

const QStringList AssemblyTerms = {
    "MOV", "ADD", "SUB", "MUL", "DIV", "AND", "OR", "XOR", "NOT", "SHL",
    "SHR", "CMP", "JMP", "JE", "JNE", "JG", "JL", "JGE", "JLE", "CALL",
    "RET", "PUSH", "POP", "LEA", "NOP", "INT", "HLT", "INC", "DEC", "AL",
    "BL", "CL", "DL", "AX", "BX", "CX", "DX", "EAX", "EBX", "ECX",
    "EDX", "RAX", "RBX", "RCX", "RDX", "RSP", "RBP", "RSI", "RDI", "ESP",
    "EBP", "ESI", "EDI", "CS", "DS", "SS", "ES", "FS", "GS"
};

const QStringList CTerms = {
    "char", "int", "float", "double", "short", "long", "unsigned", "signed", "void", "enum",
    "struct", "union", "typedef", "const", "volatile", "static", "extern", "auto", "register", "inline",
    "sizeof", "typeof", "printf", "scanf", "malloc", "free", "calloc", "realloc", "return", "break",
    "continue", "goto", "if", "else", "switch", "case", "default", "for", "while", "do",
    "define", "include", "macro", "assert", "pointer", "reference", "function", "callback", "file", "fopen"
};

const QStringList RustTerms = {
    "fn", "let", "mut", "const", "static", "if", "else", "match", "for", "while",
    "loop", "break", "continue", "return", "struct", "enum", "trait", "impl", "use", "mod",
    "pub", "crate", "self", "super", "as", "dyn", "await", "async", "Box", "Rc",
    "Arc", "RefCell", "Mutex", "Atomic", "Option", "Result", "Vec", "HashMap", "HashSet",
    "String", "slice", "array", "tuple", "pointer", "unsafe", "macro", "derive", "type", "size_of",
    "align_of", "default", "where", "type_id"
};

const QStringList FortranTerms = {
    "program", "end", "implicit", "none", "integer", "real", "double", "complex", "logical", "character",
    "parameter", "dimension", "allocate", "deallocate", "do", "if", "else", "elseif", "select", "case",
    "switch", "continue", "return", "call", "subroutine", "function", "module", "use", "interface", "contains",
    "extern", "open", "close", "read", "write", "print", "format", "pause", "wait", "inquire",
    "query", "where", "forall", "array", "rank", "reshape", "transpose", "data"
};

const QStringList AdaTerms = {
    "procedure", "function", "package", "type", "record", "access", "exception", "subtype", "tagged", "abstract",
    "private", "public", "protected", "overriding", "overloading", "generic", "body", "begin", "end", "loop",
    "exit", "for", "if", "else", "elsif", "case", "when", "select", "others", "task",
    "entry", "accept", "terminate", "raise", "handle", "is", "not", "or", "and", "xor", "mod",
    "rem", "divide", "relaxed", "true", "false", "null", "with", "use", "context", "in", "out"
};

const QStringList SwiftTerms = {
    "var", "let", "func", "class", "struct", "enum", "protocol", "extension", "import", "guard",
    "if", "else", "switch", "case", "default", "for", "while", "repeat", "break", "continue",
    "return", "defer", "throw", "try", "catch", "async", "await", "self", "super",
    "init", "deinit", "override", "typealias", "static", "final", "public", "private", "internal",
    "fileprivate", "open", "lazy", "required", "dynamic", "inout", "some", "any", "never"
};

const QStringList KotlinTerms = {
    "val", "var", "fun", "class", "object", "interface", "data", "enum", "sealed", "when",
    "if", "else", "for", "while", "do", "break", "continue", "return", "try", "catch",
    "finally", "throw", "null", "in", "out", "override", "abstract", "final", "open", "companion",
    "init", "constructor", "delegate", "lateinit", "suspend", "with", "this", "super", "const", "typealias"
};

const QStringList PhpTerms = {
    "echo", "print", "var", "public", "private", "protected", "class", "function", "return", "if",
    "else", "elseif", "switch", "case", "default", "for", "while", "do", "break", "continue",
    "try", "catch", "finally", "throw", "isset", "unset", "empty", "include", "require", "include_once",
    "require_once", "array", "object", "self", "static", "new", "const", "namespace", "use", "trait",
    "abstract", "final", "interface", "extends", "implements", "instanceof"
};

const QStringList RubyTerms = {
    "def", "end", "class", "module", "include", "extend", "if", "elsif", "else", "unless",
    "case", "when", "while", "until", "for", "break", "next", "redo", "retry", "begin",
    "rescue", "ensure", "raise", "yield", "self", "super", "new", "return", "attr_reader", "attr_writer",
    "attr_accessor", "private", "protected", "public", "alias", "undef", "defined?", "include", "extend",
    "initialize", "each", "map", "select", "reject", "find", "collect"
};

const QStringList TclTerms = {
    "proc", "args", "global", "return", "if", "elseif", "else", "for", "while", "foreach",
    "switch", "break", "continue", "try", "catch", "throw", "rename", "unset", "eval", "exec",
    "source", "append", "incr", "lappend", "lindex", "llength", "lrange", "list", "split", "join",
    "dict", "array", "format", "regexp", "regsub", "string", "scan", "expr", "clock", "file",
    "open", "close", "puts", "gets", "fconfigure", "fopen", "fclose", "fputs"
};

const QStringList RTerms = {
    "if", "else", "for", "while", "repeat", "break", "next", "return", "function", "list",
    "data.frame", "matrix", "vector", "array", "factor", "numeric", "integer", "character", "logical",
    "print", "cat", "summary", "str", "head", "tail", "plot", "hist", "boxplot", "lm",
    "glm", "cor", "mean", "sd", "var", "t.test", "aov", "anova", "chisq.test", "prop.test",
    "apply", "lapply", "sapply", "tapply", "mapply", "sweep", "merge", "reshape", "rbind", "cbind"
};

const QStringList ObjectiveCTerms = {
    "int", "float", "double", "char", "NSString", "NSArray", "NSDictionary", "id", "SEL", "BOOL",
    "NSObject", "@interface", "implementation", "protocol", "delegate", "property", "synthesize", "atomic",
    "nonatomic", "readonly", "readwrite", "retain", "autorelease", "release", "alloc", "init", "dealloc",
    "super", "self", "if", "else", "for", "while", "switch", "case", "break", "continue",
    "return", "try", "catch", "finally", "throw", "performSelector", "respondsToSelector", "hasPrefix", "isEqualToString"
};

const QStringList GroovyTerms = {
    "def", "class", "interface", "abstract", "static", "public", "private", "protected", "void", "return",
    "if", "else", "elseif", "switch", "case", "default", "for", "while", "do", "break",
    "continue", "try", "catch", "finally", "throw", "assert", "synchronized", "import", "package", "new",
    "this", "super", "extends", "implements", "yield", "in", "out", "with", "each", "collect",
    "find", "grep", "inject", "sort", "join", "split", "trim"
};

const QStringList MatlabTerms = {
    "function", "end", "if", "elseif", "else", "switch", "case", "otherwise", "for", "while",
    "break", "continue", "return", "try", "catch", "disp", "fprintf", "input", "load", "save",
    "clear", "clc", "close", "plot", "figure", "axis", "xlabel", "ylabel", "title", "legend",
    "mean", "std", "var", "sum", "size", "length", "reshape", "sort", "unique", "concat",
    "cell", "struct", "table", "array", "matrix", "zeros", "ones", "rand", "randn", "eig"
};

const QStringList HaskellTerms = {
    "let", "in", "where", "if", "then", "else", "case", "of", "data", "type",
    "newtype", "class", "instance", "module", "import", "qualified", "as", "do", "return", "fail",
    "bind", "forall", "IO", "Monad", "Functor", "Applicative", "foldl", "foldr", "map",
    "filter", "foldl1", "foldr1", "concat", "zip", "unzip", "length", "head", "tail", "last", "init"
};

const QStringList PerlTerms = {
    "my", "our", "local", "sub", "package", "use", "require", "import", "print", "say",
    "chomp", "split", "join", "push", "pop", "shift", "unshift", "foreach", "for", "while",
    "if", "elsif", "else", "unless", "case", "when", "default", "grep", "map",
    "sort", "reverse", "scalar", "ref", "bless", "die", "warn", "eval", "BEGIN", "END",
    "use", "strict", "warnings", "return", "continue", "defined", "exists", "delete"
};


QStringList correctValueTexts = {"none"};

// Create a vector<QList<QList<QString>> containing all the QStringLists
const QVector<QStringList> AllTerms = {
    CPlusPlusTerms,
    PythonTerms,
    BashTerms,
    JavaTerms,
    JavaScriptTerms,
    AssemblyTerms,
    CTerms,
    RustTerms,
    FortranTerms,
    AdaTerms,
    SwiftTerms,
    KotlinTerms,
    PhpTerms,
    RubyTerms,
    TclTerms,
    RTerms,
    ObjectiveCTerms,
    GroovyTerms,
    MatlabTerms,
    HaskellTerms,
    PerlTerms
};
