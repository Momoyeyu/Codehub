# how to read and write variable in class
class HelloWorld

  def initialize(myname = "Ruby", myage = 0)
    @name = myname
    @age = myage
  end

  # "accessor" equal to "reader & writer"
  attr_accessor :age

  # method to read @name (must be def to read)
  # equal to "attr_reader :name"
  def name
    @name
  end

  # method to write @name (must be def to write)
  # equal to "attr_writer :name"
  def name=(value)
    @name = value
  end

  def sayhello
    # the "self" here is the "receiver" of "name method"
    # "name" behind "self" is not variable but method.
    puts "Hello, #{self.name()}!" # or "self.name"
    puts "Hi, #{@name}!"
  end

end

bob = HelloWorld.new("Jay")
p bob.name  # calling "name" method here, not variable
bob.name = "Bob" # calling "name=" method here, not variable
p bob.name
bob.sayhello
