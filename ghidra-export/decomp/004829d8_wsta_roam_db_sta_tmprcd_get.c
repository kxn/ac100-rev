// func wsta_roam_db_sta_tmprcd_get @ 004829d8 size=140

undefined4 wsta_roam_db_sta_tmprcd_get(int param_1,void *param_2)

{
  void *__src;
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 != (void *)0x0)) {
    FUN_004082d0(l_wsta_roam_data,0xffffffff);
    __src = (void *)FUN_00407fa0(DAT_00767560,param_1);
    if (__src != (void *)0x0) {
      uVar1 = 0;
      memcpy(param_2,__src,0x40);
    }
    FUN_00407f30(l_wsta_roam_data);
  }
  return uVar1;
}

