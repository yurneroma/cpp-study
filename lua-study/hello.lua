#! /usr/local/bin/lua


-- this is a comment
--[[
multi line comment
--]]

print("hello, world")

b = 10
print(b)
b = nil
print(b)


-- data type 
-- [[
--  nil , boolean, number(double), string, function, userdata(c 数据结构), thread, table(map， 关联数组， 可以当做map)   
-- ]]
print(type("hello, world"))
print(type(10.4*3))
print(type(print))
print(type(true))
print(type(nil))
print(type(type))


-- table example
print("tab1 example start ----")
tab1 = { key1 = "val1", key2 = "val2", "val3"}
for k, v in pairs(tab1) do
    print(k .. " - " ..  v)
end



print("tab1 new example start ----")

tab1.key1 = nil
for k, v in pairs(tab1) do
    print(k .. " - " .. v)
end


-- lua 中只有false and nil  为false, 其他都是true， 0 也是true
print("bool check ---")
print(type(false))
print(type(true))
print(type(nil))



if 0 then
    print("0 is true")
else
    print("0 is false")

end


-- number 
print("---  number type ----- ")
print(type(2))
print(type(2.0))
print(type(2e+1))
print(type(0.2e-1))
print(type(7.8762879e-06))



--- string
print("----- string -------")

string1 = "this is a string"

html = [[
<html>
<head> </head>
<body>
    <a href = "http://www.runoob.com"> new bee tuturial </a>
</body>
</html>
]]

print(string1)
print(html)


-- arithmatic 在对一个数字字符串上进行算术操作时，Lua 会尝试将这个数字字符串转成一个数字
print("2" + 6)
print("-2e2" * "6")


--- 字符串连接 .. 
--
print(".. string concat -----")
print("a" .. "b")

print(157 .. 428)


--- 使用 # 来计算字符串的长度，放在字符串前面，如下实例：
print("# to comupte the len of string ------")

str = "hello,world"
print("len of str: " .. #str)


--- 在 Lua 里，table 的创建是通过"构造表达式"来完成，最简单构造表达式是{}，用来创建一个空表。也可以在表里添加一些数据，直接初始化表:
--

local tb1 = {}

local tbl2 = {"apple", "pear", "banana"}
print(tb1)
print(tbl2)

for k, v in pairs(tbl2) do
    print("key", k)
end






a = {}
a["key"] = "value"
key = 10
a[key] = 22
a[key] = a[key] + 11

for k, v in pairs(a) do
    print(k .. ":" .. v)
end



--- function  first-calss value, 函数可以存在变量里
--
print("function start -----")
function factorial1(n)
    if n == 0 then
        return 1
    else 
        return n * factorial1(n - 1)
    end
end

print(factorial1(5))
factorial2 = factorial1
print(factorial2(6))


-- function 可以以匿名函数（anonymous function）的方式通过参数传递:
--
function testFun(tab, fun) 
    for k, v in pairs(tab) do
        print(fun(k, v))
    end
end

tab = {key1 = "val1", key2 = "val2"}
testFun(tab, 
function(key, val)
    return key .. "=" .. val;
end 
);



-- function
function max(num1, num2)
    if (num1 > num2) then
        result = num1
    else 
        result = num2
    end
    
    return result
end

print("the max is ", max(10, 4))
print("the max is ", max(5, 6))

arr = {"google", "runoob"}

function elementIterator(collection)
    local index = 0
    local count = #collection
    return function()
        index = index + 1
        if index <= count
        then 
            return collection[index]
        end
    end
end

for ele in elementIterator(arr)
do 
    print(ele)
end


--- file io 
file = io.open("test.csv", "r+")
io.input(file)
print(io.read())
print(io.read())
io.close(file)


file = io.open("test.csv", "a")
io.output(file)
io.write("-- hello.csv 末尾注释")
io.close(file)


-- advanced file io

file = io.open("test.csv", "r")
print(file:read())

file:close()


file = io.open("test.csv", "a")
file:write(" -- test -- ")
file:close()







