// func apupd_check_from_vap @ 00651090 size=188

void apupd_check_from_vap
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined1 local_7c [28];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined2 local_44;
  undefined1 auStack_42 [62];
  
  local_4c = 0x3132372e;
  local_48 = 0x302e302e;
  local_44 = 0x3100;
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  memset(auStack_42,0,0x36);
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  FUN_0051a7a8(&local_4c,&local_60);
  for (uVar1 = 0; uVar1 < 0x14; uVar1 = uVar1 + 1) {
    local_7c[uVar1] = *(undefined1 *)((int)&local_res0 + uVar1);
  }
  FUN_004085c0(local_60,local_5c,local_58,local_54,local_50);
  return;
}

