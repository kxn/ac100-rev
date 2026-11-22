// func DesEncrypt @ 0043ddbc size=280

void DesEncrypt(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = 0;
  uVar1 = Get7Bits(param_2,0);
  local_20 = CONCAT13(uVar1,local_20._1_3_);
  uVar1 = Get7Bits(param_2,7);
  local_20._1_3_ = CONCAT12(uVar1,local_20._2_2_);
  uVar1 = Get7Bits(param_2,0xe);
  local_20._2_2_ = CONCAT11(uVar1,(undefined1)local_20);
  uVar1 = Get7Bits(param_2,0x15);
  local_20 = CONCAT31(local_20._0_3_,uVar1);
  uVar1 = Get7Bits(param_2,0x1c);
  local_1c = CONCAT13(uVar1,local_1c._1_3_);
  uVar1 = Get7Bits(param_2,0x23);
  local_1c._1_3_ = CONCAT12(uVar1,local_1c._2_2_);
  uVar1 = Get7Bits(param_2,0x2a);
  local_1c._2_2_ = CONCAT11(uVar1,(undefined1)local_1c);
  uVar1 = Get7Bits(param_2,0x31);
  local_1c = CONCAT31(local_1c._0_3_,uVar1);
  endes(param_1,&local_20,param_3);
  return;
}

