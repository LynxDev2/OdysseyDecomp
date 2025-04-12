import clang.cindex as libclang
from clang.cindex import CursorKind
from pathlib import Path
from functools import cache

ROOT = Path(__file__).parent.parent

@cache
def get_common_compiler_args():
    cd = libclang.CompilationDatabase.fromDirectory(ROOT/'build')
    arguments = {x.filename: list(x.arguments) for x in cd.getAllCompileCommands() if str(ROOT/'src') in x.filename or str(ROOT/'lib/al') in x.filename}

    for (file,args) in arguments.items():
        # remove "-o" and one following argument from all entries
        for i in range(len(args)):
            if args[i] == '-o':
                args.pop(i)
                args.pop(i)
                break
        # remove last argument = filename
        args.pop()


    common_args = next(iter(arguments.values()))

    for (file,args) in arguments.items():
        common_args = [arg for arg in common_args if arg in args]

    for (file,args) in arguments.items():
        args = [arg for arg in args if arg not in common_args]
        if len(args) > 0:
            print("ERROR: Found additional arguments for", file, ", arguments:", args)
    
    return common_args

index = libclang.Index.create()
tu = index.parse(str(ROOT/'src'/'Item'/'Coin.cpp'), get_common_compiler_args())

cursor = tu.cursor

def extract_default_arguments(cursor):
    for param in cursor.get_children():
        param_has_default = False
        default_value = None
        print(param.spelling)

        # Check if the parameter has children, indicating a default argument
        for child in param.get_children():
            param_has_default = True
            break

        if param_has_default:
            # Tokenize the parameter's source range
            tokens = list(param.get_tokens())
            for i, token in enumerate(tokens):
                if token.spelling == '=' and i + 1 < len(tokens):
                    # The token following '=' is the default value
                    default_value = tokens[i + 1].spelling
                    break

        #print(f"Parameter: {param.spelling}, Default Value: {default_value}")

def debug_node(node: libclang.Cursor):
    for child in node.get_children():
        debug_node(child)
    if node.kind == CursorKind.FUNCTION_DECL and "abc" in node.displayname:
        extract_default_arguments(cursor)
        print("Found:", node.displayname, node.mangled_name)

debug_node(cursor)
