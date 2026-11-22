; func uac_wstation_free_all_sta_in_ap @ 0x00632c04 size=0x18
  632c04:	10a00003 	beqz	a1,0x632c14
  632c08:	00000000 	nop
  632c0c:	3c050063 	lui	a1,0x63
  632c10:	24a50f20 	addiu	a1,a1,3872
  632c14:	0818f13f 	j	0x63c4fc
  632c18:	00003021 	move	a2,zero
