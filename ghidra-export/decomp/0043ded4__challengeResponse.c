// func _challengeResponse @ 0043ded4 size=180

void _challengeResponse(undefined4 param_1,void *param_2,int param_3)

{
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  memcpy(&local_28,param_2,0x10);
  DesEncrypt(param_1,&local_28,param_3);
  DesEncrypt(param_1,(int)&local_24 + 3,param_3 + 8);
  DesEncrypt(param_1,(int)&local_1c + 2,param_3 + 0x10);
  return;
}

