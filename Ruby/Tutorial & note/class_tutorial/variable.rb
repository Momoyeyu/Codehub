# class variable (like static var in C or Java)
class Static

  @@count = 0 # static var for the class Static, all instance share this
  
  def Static.count
    return @@count # "return: is not necessary here, but I like to write it out
  end

  def initialize(name = "Ruby")
    puts "initialize"
    @name = name
  end

  def hello
    @@count += 1
    puts "Hello, #{@name}"
    puts "For the #{@@count} time(s) in total"
  end
end

bob = Static.new("bob")
alice = Static.new("alice")
ruby = Static.new

p Static.count
bob.hello
alice.hello
ruby.hello
p Static.count
