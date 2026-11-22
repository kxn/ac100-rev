// func uac_hash_new_core @ 00518ae0 size=300

int * uac_hash_new_core(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)0x0;
  if ((((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) &&
     (piVar2 = (int *)uac_mem_malloc_my(0x20,0x94), piVar2 != (int *)0x0)) {
    iVar1 = uac_mem_calloc_my(param_5,0xc,0x99);
    iVar3 = 0;
    piVar2[7] = iVar1;
    if (iVar1 == 0) {
      uac_mem_free_my(piVar2);
      piVar2 = (int *)0x0;
    }
    else {
      if (param_5 == 0) {
        *piVar2 = param_1;
      }
      else {
        do {
          iVar1 = iVar3 * 0xc;
          iVar3 = iVar3 + 1;
          uac_list_init(piVar2[7] + iVar1);
        } while (iVar3 != param_5);
        *piVar2 = param_1;
      }
      piVar2[1] = param_2;
      piVar2[2] = param_3;
      piVar2[6] = param_4;
      piVar2[5] = iVar3;
      piVar2[4] = 0;
    }
  }
  return piVar2;
}

