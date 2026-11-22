// func apmngr_support_sub_capacity_get @ 0052a860 size=56

void apmngr_support_sub_capacity_get(ushort *param_1,void *param_2)

{
  uint uVar1;
  
  if ((param_1 != (ushort *)0x0) && (param_2 != (void *)0x0)) {
    uVar1 = (uint)sub_cap_num;
    *param_1 = sub_cap_num;
    memcpy(param_2,&sub_cap_supp,uVar1 << 3);
    return;
  }
  return;
}

