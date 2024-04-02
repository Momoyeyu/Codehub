# extend class method

class String # extend class String
  public # all methods below this keyword will be public method
         # since all method except inilialize are public by default, the keyword here is for explicity

  def count_word
    return self.split(/\s+/).size
  end
end

str = "A simple string example"
p str.count_word
