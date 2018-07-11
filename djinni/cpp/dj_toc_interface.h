class IDJToC 
{
   public:
      // call by Mainactivity to deal action
      virtual void iregister(std::string name,int key) = 0;
       virtual void ilogin(std::string name,int key,int imei) = 0;
       virtual bool initGrpcClient() =0;
};