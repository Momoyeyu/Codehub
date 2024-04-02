class RC4
private
  def RC4.generate_s_box(key)
    if key.instance_of?(String)
      tmp = Array.new
      key.size.times do |i|
        tmp[i] = key[i].ord
      end
      key = tmp
    end
    s_box = Array.new
    256.times do |i|
      s_box[i] = i
    end
    j = 0
    256.times do |i|
      j = (j + s_box[i] + key[i % key.length]) % 256 # T[i] = key[i % key.length]
      s_box[i], s_box[j] = s_box[j], s_box[i]
    end
    return s_box
  end

  def RC4.generate_t_box(s_box)
    j = 0
    t_box = Array.new
    256.times do |i|
      j = (j + s_box[i]) % 256
      t_box[i] = ((s_box[i] + s_box[j]) % 256)
    end
    return t_box
  end

public
  def RC4.encrypt(message , key, code = true)
    s_box = generate_s_box(key)
    t_box = generate_t_box(s_box)
    if code # return in 0~255 code
      cipher = Array.new
      message.length.times do |i|
        cipher[i] = message[i].ord ^ t_box[i % 256]
      end
      return cipher
    else # return as string
      cipher = ""
      message.length.times do |i|
        cipher += (message[i].ord ^ t_box[i % 256]).chr
      end
      return cipher
    end
  end

  def RC4.decrypt(cipher , key, code = false)
    return RC4.encrypt(cipher, key, code)
  end

end

key = [1, 2, 3, 4, 5]
message = "D0_u_Kn0w_Rc4?"
cipher =  RC4.encrypt(message, key)
print cipher, "\n"
message_decrypt = RC4.decrypt(cipher, key)
print message_decrypt, "\n"

key = "my key"
message = "D0_u_Kn0w_Rc4?"
cipher =  RC4.encrypt(message, key, false)
print cipher, "\n"
message_decrypt = RC4.decrypt(cipher, key, true)
print message_decrypt, "\n"
