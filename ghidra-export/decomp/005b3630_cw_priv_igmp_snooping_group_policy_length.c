// func cw_priv_igmp_snooping_group_policy_length @ 005b3630 size=112

short cw_priv_igmp_snooping_group_policy_length(int *param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  
  sVar2 = 0;
  if (param_1 != (int *)0x0) {
    sVar2 = 4;
    if (*param_1 != 0) {
      iVar3 = 0;
      do {
        cVar1 = *(char *)(param_1[1] + iVar3 * 0x18 + 4);
        if (cVar1 == '\x01') {
          sVar2 = sVar2 + 6;
        }
        else if (cVar1 == '\x02') {
          sVar2 = sVar2 + 0x12;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != *param_1);
    }
  }
  return sVar2;
}

