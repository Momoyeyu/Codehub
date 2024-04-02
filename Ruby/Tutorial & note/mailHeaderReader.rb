def mail_header_reader;
  mail_text = File.read(mail_path);
  mail_text.each_line do |line|
    case line
    when /^From/i  # i 表示不区分大小写
      puts "发信人：#{line}"
    when /^To/i
      puts "收信人：#{line}"
    when /^Subject/i
      puts "邮件主题：#{line}"
    when /^$/  # 匹配空行
      puts "头部解析完成"
      exit
    else
      next    # continue
    end
  end
end

