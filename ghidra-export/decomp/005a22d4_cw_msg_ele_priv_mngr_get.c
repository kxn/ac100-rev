// func cw_msg_ele_priv_mngr_get @ 005a22d4 size=44

undefined * cw_msg_ele_priv_mngr_get(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if ((param_1 & 0xffff) < 0xc1) {
    puVar1 = (&PTR_g_cw_msg_ele_priv_cwver_mngr_006e6700)[param_1 & 0xffff];
  }
  return puVar1;
}

