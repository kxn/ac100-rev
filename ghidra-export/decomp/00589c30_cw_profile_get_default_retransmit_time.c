// func cw_profile_get_default_retransmit_time @ 00589c30 size=76

undefined4 cw_profile_get_default_retransmit_time(void)

{
  undefined4 uVar1;
  
  if (l_profile == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_profile_get_default_retransmit_time",0xa40,
           "l_profile");
    uVar1 = 0x3c;
  }
  else {
    uVar1 = *(undefined4 *)(l_profile + 0x138);
  }
  return uVar1;
}

