// func _apdb_radio_copy @ 005ffcdc size=204

void _apdb_radio_copy(void *param_1,void *param_2,int param_3)

{
  void *__s;
  int iVar1;
  
  if ((param_1 != (void *)0x0) && (param_2 != (void *)0x0)) {
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      if (*(int *)((int)param_1 + 0x110) != 0) {
        _apdb_radio_free(*(int *)((int)param_1 + 0x110),1);
        *(undefined4 *)((int)param_1 + 0x110) = 0;
      }
      memcpy(param_1,param_2,0x114);
      *(undefined4 *)((int)param_1 + 0x110) = 0;
      if (*(int *)((int)param_2 + 0x110) != 0) {
        __s = (void *)FUN_00408450(0x114,0x2c4);
        *(void **)((int)param_1 + 0x110) = __s;
        if (__s == (void *)0x0) {
          return;
        }
        memset(__s,0,0x114);
        _apdb_radio_copy(*(undefined4 *)((int)param_1 + 0x110),*(undefined4 *)((int)param_2 + 0x110)
                         ,1);
      }
      param_1 = (void *)((int)param_1 + 0x114);
      param_2 = (void *)((int)param_2 + 0x114);
    }
  }
  return;
}

