class Hello # the first letter of class name MUST BE upper case
	def initialize(myname = "Ruby")
		@name = myname
  end

  def sayhello
    puts "hello #{@name}"
  end
end

momoyeyu = Hello.new("momo")
ruby = Hello.new

momoyeyu.sayhello
ruby.sayhello
