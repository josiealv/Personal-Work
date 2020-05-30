def isValid(s):
    stack=[]
    for i in s:    
        if i == '(' or i=='{' or i =='[':
            stack.append(i)
        else:
            if len(stack)!=0:
                if i==')' and stack[-1]=='(':
                    stack.pop()
                elif i==']' and stack[-1]=='[':
                    stack.pop()
                elif i=='}' and stack[-1]=='{':
                    stack.pop()
                else:
                    return False
            else:
                return False

    if len(stack)==0:
        return True

    return False

print (isValid(input("Enter parentheses: ")))