; func uac_wstation_free_all_sta_in_radio @ 0x00632a80 size=0x18
  632a80:	10c00003 	beqz	a2,0x632a90
  632a84:	30a500ff 	andi	a1,a1,0xff
  632a88:	3c060063 	lui	a2,0x63
  632a8c:	24c60f20 	addiu	a2,a2,3872
  632a90:	0818f0eb 	j	0x63c3ac
  632a94:	00003821 	move	a3,zero
