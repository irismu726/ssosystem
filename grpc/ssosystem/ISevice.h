  
class IService{
  virtual int  callback_reg(bool result)=0;
  virtual callback_login(bool result,int session)=0;
  virtual callback_out(int session)=0;
}