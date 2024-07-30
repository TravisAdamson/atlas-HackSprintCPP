#include "LanguageTerms.h"

// CPlusPlusTerms
const QStringList CPlusPlusTerms = {
    "char", "float", "double", "short", "long", "long long",
    "unsigned int", "unsigned short", "unsigned long", "unsigned long long",
    "long double", "array", "pointer", "reference", "function",
    "struct", "union", "enum", "typedef", "class", "bool", "int",
    "const", "volatile", "static", "extern", "inline", "template",
    "namespace", "public", "protected", "private", "friend", "virtual",
    "override", "final", "dynamic_cast", "static_cast", "const_cast", "reinterpret_cast",
    "operator", "new", "delete", "this", "typeid", "sizeof", "decltype", "alignas", "alignof"
};

// PythonTerms
const QStringList PythonTerms = {
    "int", "float", "str", "list", "tuple", "dict", "set", "bool", "bytes", "bytearray",
    "None", "if", "else", "elif", "for", "while", "break", "continue", "pass", "return",
    "def", "class", "import", "from", "as", "with", "try", "except", "finally", "raise",
    "lambda", "map", "filter", "reduce", "comprehensions", "generator", "yield",
    "open", "close", "read", "write", "append", "seek", "format", "f-string", "print",
    "type", "isinstance", "issubclass", "staticmethod", "classmethod", "property", "self"
};

// BashTerms
const QStringList BashTerms = {
    "echo", "printf", "cat", "grep", "awk", "sed", "cut", "sort", "uniq", "find",
    "locate", "xargs", "head", "tail", "chmod", "chown", "ln", "cp", "mv", "rm",
    "touch", "mkdir", "rmdir", "ls", "pwd", "cd", "bash", "sh", "source", "export",
    "unset", "alias", "unalias", "history", "jobs", "fg", "bg", "kill", "ps", "top",
    "ps aux", "tar", "gzip", "gunzip", "zip", "unzip", "wget", "curl", "sed -e", "awk '{print $1}'",
    "if", "then", "else", "elif", "fi", "for", "in", "do", "done", "while", "until",
    "case", "esac", "function", "return", "local", "getopts", "shift", "test", "[", "]"
};

// JavaTerms
const QStringList JavaTerms = {
    "int", "float", "double", "char", "byte", "short", "long", "boolean", "String", "array",
    "class", "interface", "enum", "abstract", "final", "static", "public", "private", "protected", "void",
    "new", "this", "super", "extends", "implements", "instanceof", "throws", "throw", "try",
    "catch", "finally", "assert", "synchronized", "volatile", "transient", "default", "constructor", "destructor",
    "method", "field", "variable", "package", "import", "main", "return", "break",
    "continue", "if", "else", "switch", "case", "default", "for", "while", "do", "instanceof"
};

// JavaScriptTerms
const QStringList JavaScriptTerms = {
    "var", "let", "const", "function", "return", "if", "else", "switch", "case", "default",
    "for", "while", "do", "break", "continue", "try", "catch", "finally", "throw", "async",
    "await", "class", "extends", "constructor", "super", "static", "import", "export", "module", "default",
    "this", "prototype", "new", "delete", "typeof", "instanceof", "void", "null", "undefined", "NaN",
    "Infinity", "Promise", "fetch", "map", "filter", "reduce", "concat", "slice", "splice", "push",
    "pop", "shift", "unshift", "toString", "valueOf", "JSON", "Object", "Array", "String", "Number", "Boolean", "Symbol"
};

// AssemblyTerms
const QStringList AssemblyTerms = {
    "MOV", "ADD", "SUB", "MUL", "DIV", "AND", "OR", "XOR", "NOT", "SHL",
    "SHR", "CMP", "JMP", "JE", "JNE", "JG", "JL", "JGE", "JLE", "CALL",
    "RET", "PUSH", "POP", "LEA", "NOP", "INT", "HLT", "INC", "DEC", "AL",
    "BL", "CL", "DL", "AX", "BX", "CX", "DX", "EAX", "EBX", "ECX",
    "EDX", "RAX", "RBX", "RCX", "RDX", "RSP", "RBP", "RSI", "RDI", "ESP",
    "EBP", "ESI", "EDI", "CS", "DS", "SS", "ES", "FS", "GS", "MOVZX", "MOVSX"
};

// CTerms
const QStringList CTerms = {
    "char", "int", "float", "double", "short", "long", "unsigned", "signed", "void", "enum",
    "struct", "union", "typedef", "const", "volatile", "static", "extern", "auto", "register", "inline",
    "sizeof", "typeof", "printf", "scanf", "malloc", "free", "calloc", "realloc", "return", "break",
    "continue", "goto", "if", "else", "switch", "case", "default", "for", "while", "do",
    "define", "include", "macro", "assert", "pointer", "reference", "function", "callback", "file", "fopen",
    "static_assert", "restrict"
};

// RustTerms
const QStringList RustTerms = {
    "fn", "let", "mut", "const", "static", "if", "else", "match", "for", "while",
    "loop", "break", "continue", "return", "struct", "enum", "trait", "impl", "use", "mod",
    "pub", "crate", "self", "super", "as", "dyn", "await", "async", "Box", "Rc",
    "Arc", "RefCell", "Mutex", "Atomic", "Option", "Result", "Vec", "HashMap", "HashSet",
    "String", "slice", "array", "tuple", "pointer", "unsafe", "macro", "derive", "type", "size_of",
    "align_of", "default", "where", "type_id", "trait"
};

// FortranTerms
const QStringList FortranTerms = {
    "program", "end", "implicit", "none", "integer", "real", "double", "complex", "logical", "character",
    "parameter", "dimension", "allocate", "deallocate", "do", "if", "else", "elseif", "select", "case",
    "switch", "continue", "return", "call", "subroutine", "function", "module", "use", "interface", "contains",
    "extern", "open", "close", "read", "write", "print", "format", "pause", "wait", "inquire",
    "query", "where", "forall", "array", "rank", "reshape", "transpose", "data", "save", "read", "write"
};

// PhpTerms
const QStringList PhpTerms = {
    "echo", "print", "var", "public", "private", "protected", "class", "function", "return", "if",
    "else", "elseif", "switch", "case", "default", "for", "while", "do", "break", "continue",
    "try", "catch", "finally", "throw", "isset", "unset", "empty", "include", "require", "include_once",
    "require_once", "array", "object", "self", "static", "new", "const", "namespace", "use", "trait",
    "abstract", "final", "interface", "extends", "implements", "instanceof", "yield"
};

// RubyTerms
const QStringList RubyTerms = {
    "def", "end", "class", "module", "include", "extend", "if", "elsif", "else", "unless",
    "case", "when", "while", "until", "for", "break", "next", "redo", "retry", "begin",
    "rescue", "ensure", "raise", "yield", "self", "super", "new", "return", "attr_reader", "attr_writer",
    "attr_accessor", "private", "protected", "public", "alias", "undef", "defined?", "include", "extend",
    "initialize", "each", "map", "select", "reject", "find", "collect", "module_function"
};

// ObjectiveCTerms
const QStringList ObjectiveCTerms = {
    "int", "float", "double", "char", "NSString", "NSArray", "NSDictionary", "id", "SEL", "BOOL",
    "NSObject", "@interface", "implementation", "protocol", "delegate", "property", "synthesize", "atomic",
    "nonatomic", "readonly", "readwrite", "retain", "autorelease", "release", "alloc", "init", "dealloc",
    "super", "self", "if", "else", "for", "while", "switch", "case", "break", "continue",
    "return", "try", "catch", "finally", "throw", "performSelector", "respondsToSelector", "hasPrefix", "isEqualToString",
    "NSLog", "NSUserDefaults"
};

// PerlTerms
const QStringList PerlTerms = {
    "my", "our", "local", "sub", "package", "use", "require", "import", "print", "say",
    "chomp", "split", "join", "push", "pop", "shift", "unshift", "foreach", "for", "while",
    "if", "elsif", "else", "unless", "case", "when", "default", "grep", "map",
    "sort", "reverse", "scalar", "ref", "bless", "die", "warn", "eval", "BEGIN", "END",
    "use", "strict", "warnings", "return", "continue", "defined", "exists", "delete", "state"
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
    PhpTerms,
    RubyTerms,
    ObjectiveCTerms,
    PerlTerms
};

const QStringList Titles = {
    "C++", "Python", "Bash", "Java", "JavaScript", "Assembly", "C", "Rust", "Fortran",
    "PHP", "Ruby", "Objective-C", "Perl"
};

const std::unordered_map<std::string, std::string> explanationMap = {
        {"if", "if-explination"},
        {"filler", "filler-explination"},
        {"echo", "echo-explination"},
        {"void", "void-explination"},
        {"include", "include-explination"},
        {"do", "do-explination"},
        {"for", "for-explination"}
    };