# class constance
class App

  # define a constance
  Version = "1.0"

  def initialize
    puts "initialize!"
    # do something
  end

end

# use the constance
p App::Version
app = App.new
# the class constance can't be reference by instance
print app::Version # run into error"is not a class/module (TypeError)"

