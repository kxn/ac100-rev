// func radius_pair_gen @ 00449460 size=812

char * radius_pair_gen(undefined4 param_1,char *param_2,byte *param_3,uint param_4,int param_5)

{
  char *pcVar1;
  char *__dest;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  size_t sVar5;
  char acStack_228 [4];
  undefined4 local_224;
  char local_220 [516];
  
  if (1 < (int)param_4) {
    uVar3 = (uint)param_3[1];
    if (((int)uVar3 <= (int)param_4) && (1 < uVar3)) {
      if ((param_4 != uVar3) &&
         (param_2 = (char *)radius_pair_gen(param_1,param_2,param_3 + uVar3,param_4 - uVar3,param_5)
         , param_2 == (char *)0x0)) {
        return (char *)0x0;
      }
      sVar5 = uVar3 - 2;
      pbVar4 = param_3 + 2;
      if ((param_5 << 0x10 | (uint)*param_3) == 0x1a) {
        if (3 < (int)sVar5) {
          memcpy(&local_224,pbVar4,4);
          iVar2 = radius_dict_getvend_by_value(param_1,local_224);
          if (iVar2 == 0) {
            return param_2;
          }
          pcVar1 = (char *)radius_pair_gen(param_1,param_2,param_3 + 6,uVar3 - 6,local_224);
          return pcVar1;
        }
      }
      else {
        pcVar1 = (char *)radius_dict_getattr_by_value(param_1);
        if (pcVar1 == (char *)0x0) {
          local_220[0] = '\0';
          pbVar4 = param_3 + (uVar3 - 2);
          for (; param_3 != pbVar4; param_3 = param_3 + 1) {
            sprintf(acStack_228,"%2.2X",(uint)param_3[2]);
            strcat(local_220,acStack_228);
          }
        }
        else {
          __dest = (char *)uac_mem_malloc_my(0x154,0x174);
          if (__dest != (char *)0x0) {
            pair_malloc = pair_malloc + 1;
            memset(__dest,0,0x154);
            *(char **)(__dest + 0x150) = param_2;
            strcpy(__dest,pcVar1);
            *(undefined4 *)(__dest + 0x44) = *(undefined4 *)(pcVar1 + 0x44);
            *(undefined4 *)(__dest + 0x48) = *(undefined4 *)(pcVar1 + 0x48);
            param_2 = __dest;
            switch(*(undefined4 *)(pcVar1 + 0x48)) {
            case 0:
              memcpy(__dest + 0x50,pbVar4,sVar5);
              __dest[uVar3 + 0x4e] = '\0';
              *(size_t *)(__dest + 0x4c) = sVar5;
              return __dest;
            case 1:
            case 2:
              if (sVar5 == 4) {
                memcpy(&local_224,pbVar4,4);
                *(undefined4 *)(__dest + 0x4c) = local_224;
                return __dest;
              }
              break;
            default:
              break;
            case 6:
              if (sVar5 == 8) {
                sVar5 = 8;
LAB_004496b4:
                memcpy(__dest + 0x50,pbVar4,sVar5);
                return __dest;
              }
              break;
            case 7:
              if (sVar5 == 0x10) {
                sVar5 = 0x10;
                goto LAB_004496b4;
              }
              break;
            case 8:
              if (uVar3 - 4 < 0x11) {
                memcpy(__dest + 0x50,pbVar4,sVar5);
                *(size_t *)(__dest + 0x4c) = sVar5;
                return __dest;
              }
            }
          }
        }
      }
    }
  }
  while (param_2 != (char *)0x0) {
    pcVar1 = *(char **)(param_2 + 0x150);
    uac_mem_free_my(param_2);
    pair_free = pair_free + 1;
    param_2 = pcVar1;
  }
  return (char *)0x0;
}

