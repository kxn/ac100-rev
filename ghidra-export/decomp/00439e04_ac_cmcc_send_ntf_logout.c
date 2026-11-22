// func ac_cmcc_send_ntf_logout @ 00439e04 size=316

undefined4
ac_cmcc_send_ntf_logout
          (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,ushort param_7,int param_8)

{
  undefined4 uVar1;
  undefined2 *__src;
  size_t __n;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined2 local_70;
  undefined2 local_6e;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_50;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 auStack_2c [28];
  
  local_res8 = param_3;
  local_resc = param_4;
  memset(&local_30,0,0x20);
  uVar1 = 0xffffffff;
  if ((param_2 >> 0x18) - 1 < 2) {
    local_54 = 0;
    local_60 = 0x1000000;
    local_50 = 0;
    local_5c = (uint)param_7 << 0x10;
    if (param_8 == 0) {
      local_60 = 0x1010000;
    }
    local_58 = param_1;
    if (param_2 >> 0x18 == 1) {
      local_68 = 0;
      local_64 = 0;
      __src = &local_70;
      __n = 0x10;
      local_70 = 2;
      local_6c = local_res8;
      local_30 = 1;
      local_6e = (short)g_cmcc_portal_port;
    }
    else {
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_4c = 10;
      local_4a = (short)g_cmcc_portal_port;
      memcpy(&local_44,&local_res8,0x10);
      __src = &local_4c;
      local_30 = 2;
      __n = 0x1c;
    }
    memcpy(auStack_2c,__src,__n);
    uVar1 = _ac_cmcc_send_pkt(&local_60,&local_30,8,0);
  }
  return uVar1;
}

