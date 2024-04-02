def readFile(filename)
  text = File.read(filename)
  return text
end

pattern = Regexp.new(".*ha.*")
filename = "./helloworld.rb"

puts "[INFO] checking text fixing pattern: #{pattern}"
text = readFile(filename)
text.each_line do |line|
  if (pattern =~ line) != nil
    print line
  end
end

