; func cloud_mngt_radio_type_get @ 0x0048baf4 size=0x44
  48baf4:	2c82000e 	sltiu	v0,a0,14
  48baf8:	10400009 	beqz	v0,0x48bb20
  48bafc:	00001021 	move	v0,zero
  48bb00:	3c02006a 	lui	v0,0x6a
  48bb04:	2442b8a8 	addiu	v0,v0,-18264
  48bb08:	00822021 	addu	a0,a0,v0
  48bb0c:	80820000 	lb	v0,0(a0)
  48bb10:	2c43000d 	sltiu	v1,v0,13
  48bb14:	14600003 	bnez	v1,0x48bb24
  48bb18:	3c030073 	lui	v1,0x73
  48bb1c:	00001021 	move	v0,zero
  48bb20:	3c030073 	lui	v1,0x73
  48bb24:	00021080 	sll	v0,v0,0x2
  48bb28:	246317b0 	addiu	v1,v1,6064
  48bb2c:	00431021 	addu	v0,v0,v1
  48bb30:	03e00008 	jr	ra
  48bb34:	8c420000 	lw	v0,0(v0)
