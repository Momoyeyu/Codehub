# class method
# class method in ruby can't be called by instance
class HelloWorld
  def initialize
    puts "initialize!"
  end
end
def HelloWorld.hello(name = "Ruby")
  puts "Hello, #{name}"
end
HelloWorld.hello

class HelloClass
  # it didn't create a new class, but a class method here
  class << self # "self" refer to the HelloClass itself
    def hello(name = "HelloClass class")
      puts "#{name} say hello!"
    end
  end

  def self.classmethod
    puts "another class method!"
  end

  def initialize(age = 0)
    puts "initialize!"
    @age = age
  end

end

HelloClass.hello
HelloClass.classmethod
baby = HelloClass.new

baby.hello # run into error "undefined method `hello'"
# it seem that the class method can't be called by instance
