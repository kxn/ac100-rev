// func radius_pair_gen2 @ 00449974 size=448

int radius_pair_gen2(undefined4 param_1,char *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *__src;
  int iVar6;
  int iVar7;
  int local_30 [2];
  
  iVar4 = 0;
  local_30[0] = 0;
  if (2 < param_3) {
    uVar5 = (uint)(byte)param_2[1];
    while (((int)uVar5 <= param_3 && (1 < uVar5))) {
      if (param_3 == 0) {
        return iVar4;
      }
      __src = param_2 + 2;
      iVar7 = uVar5 - 2;
      if (*param_2 == '\x1a') {
        if (iVar7 < 4) goto LAB_00449b04;
        memcpy(local_30,__src,4);
        iVar7 = local_30[0];
        bVar1 = param_2[7];
        bVar2 = param_2[6];
        if (bVar1 < 2) goto LAB_00449b04;
        iVar3 = radius_dict_getvend_by_value(param_1,local_30[0]);
        iVar6 = bVar1 - 2;
        if ((iVar3 != 0) &&
           (iVar7 = radius_pair_get2(param_1,(uint)bVar2 | iVar7 << 0x10,iVar6,param_2 + 8),
           iVar7 != 0)) {
          *(int *)(iVar7 + 0x150) = iVar4;
          iVar4 = iVar7;
        }
        param_2 = param_2 + 8 + iVar6;
        param_3 = param_3 - uVar5;
        uVar5 = (uint)(byte)param_2[1];
      }
      else {
        iVar3 = radius_pair_get2(param_1,*param_2,iVar7,__src);
        if (iVar3 != 0) {
          *(int *)(iVar3 + 0x150) = iVar4;
          iVar4 = iVar3;
        }
        param_2 = __src + iVar7;
        param_3 = param_3 - uVar5;
        uVar5 = (uint)(byte)param_2[1];
      }
    }
    if (param_3 == 0) {
      return iVar4;
    }
  }
LAB_00449b04:
  while (iVar4 != 0) {
    iVar7 = *(int *)(iVar4 + 0x150);
    uac_mem_free_my(iVar4);
    pair_free = pair_free + 1;
    iVar4 = iVar7;
  }
  return 0;
}

