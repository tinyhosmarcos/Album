from django.contrib import admin
from .models import *

# Register your models here.

class JugadorInline(admin.StackedInline):
	model = Jugador


admin.site.register(Page)
admin.site.register(Country)
admin.site.register(Miscaleneo)
admin.site.register(Cromo)
admin.site.register(Jugador)
admin.site.register(Estadio)