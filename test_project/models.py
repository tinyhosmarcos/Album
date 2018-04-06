from django.db import models

class Page(models.Model):
	id=models.AutoField(primary_key=True)
	pais=models.CharField(max_length=20)
	#choices
	PAIS='PA'
	MISCALENEO='MS'
	list_diseño=((PAIS,'Pais'),(MISCALENEO,'Miscaleneo'))
	diseño=models.CharField(max_length=2,choices=list_diseño,default=PAIS)
	def __str__(self):
		return self.diseño
		
class Country(models.Model):
	page_id=models.OneToOneField(Page, on_delete=models.CASCADE,primary_key=True)
	nombre=models.CharField(max_length=20)
	def __str__(self):
		return self.nombre

class Miscaleneo(models.Model):
	page_id=models.OneToOneField(Page,on_delete=models.CASCADE,primary_key=True)
	description_text=models.CharField(max_length=300)
	description_misc=models.CharField(max_length=40)
	def __str__(self):
		return self.description_misc

class Cromo(models.Model):
	id = models.AutoField(primary_key=True)
	cromo_img=models.CharField(max_length=200)
	pub_date=models.DateTimeField('date published')
	#new add models
	page_id=models.ForeignKey(Page, on_delete=models.CASCADE)
	#choices
	JUGADOR='jr'
	ESTADIO='es'
	list_tipo=((JUGADOR,'Jugador'),(ESTADIO,'Estadio'))
	tipo=models.CharField(max_length=2,choices=list_tipo,default=JUGADOR)
	def __str__(self):
		return self.tipo

class Jugador(models.Model):
	cromo_id	=models.OneToOneField(Cromo, on_delete=models.CASCADE,primary_key=True)
	seleccion	=models.ForeignKey(Country,on_delete=models.CASCADE,default=1)
	nombres		=models.CharField(max_length=30)
	apellidos	=models.CharField(max_length=30)
	posicion	=models.CharField(max_length=20)
	peso		=models.CharField(max_length=20)
	altura		=models.CharField(max_length=20)
	club_actual	=models.CharField(max_length=40)
	f_nacimiento=models.DateField(auto_now=False, auto_now_add=False)
	def __str__(self):
		return self.nombres

class Estadio(models.Model):
	cromo_id=models.OneToOneField(Cromo,on_delete=models.CASCADE,primary_key=True)
	nombre=models.CharField(max_length=40)
	f_creacion=models.DateField(auto_now=False,auto_now_add=False)
	def __str__(self):
		return self.nombre