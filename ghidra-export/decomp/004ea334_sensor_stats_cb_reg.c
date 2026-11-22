// func sensor_stats_cb_reg @ 004ea334 size=552

undefined4 sensor_stats_cb_reg(void *param_1,undefined2 param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  void *__s;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  void *local_res0 [4];
  
  local_res0[0] = param_1;
  if ((sensor_cb_hash == 0) &&
     (sensor_cb_hash = FUN_004080a0(sensor_cb_hash_obj,sensor_cb_hash_key,sensor_cb_hash_cmp,0x14),
     sensor_cb_hash == 0)) {
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[SENSOR_ERROR]%s()/%d Create sensor cb hash failed\n";
    uVar4 = 199;
  }
  else {
    iVar2 = FUN_00408450(0x14,0xcc);
    iVar3 = sensor_cb_hash;
    if (iVar2 == 0) {
      if (sensor_err_switch == '\0') {
        return 0xffffffff;
      }
      __format = "[SENSOR_ERROR]%s()/%d out of memory\n";
      uVar4 = 0xce;
    }
    else {
      *(undefined2 *)(iVar2 + 0xc) = param_2;
      *(undefined4 *)(iVar2 + 0x10) = param_3;
      __s = (void *)FUN_00407fa0(iVar3,local_res0);
      if (__s != (void *)0x0) {
LAB_004ea3a0:
        iVar3 = FUN_004081b0((int)__s + 0x38);
        if (iVar3 != 0) {
          uVar1 = *(ushort *)(iVar2 + 0xc);
          while( true ) {
            if (*(ushort *)(iVar3 + 0xc) < uVar1) {
              FUN_00408170(iVar3,iVar2);
              return 0;
            }
            iVar3 = FUN_00408680();
            if (iVar3 == 0) break;
            uVar1 = *(ushort *)(iVar2 + 0xc);
          }
        }
        FUN_004086b0((int)__s + 0x38,iVar2);
        return 0;
      }
      __s = (void *)FUN_00408450(0x44,0xd6);
      if (__s == (void *)0x0) {
        FUN_00407df0(iVar2);
        if (sensor_err_switch == '\0') {
          return 0xffffffff;
        }
        __format = "[SENSOR_ERROR]%s()/%d Malloc failed\n";
        uVar4 = 0xda;
      }
      else {
        memset(__s,0,0x44);
        FUN_0051ad88((int)__s + 0x38);
        memcpy(__s,local_res0[0],0x38);
        iVar3 = FUN_00408380(sensor_cb_hash,__s);
        if (iVar3 == 0) goto LAB_004ea3a0;
        FUN_00407df0(iVar2);
        FUN_00407df0(__s);
        if (sensor_err_switch == '\0') {
          return 0xffffffff;
        }
        __format = "[SENSOR_ERROR]%s()/%d Add cb mngr to hash failed\n";
        uVar4 = 0xe4;
      }
    }
  }
  printf(__format,"sensor_stats_cb_reg",uVar4);
  return 0xffffffff;
}

