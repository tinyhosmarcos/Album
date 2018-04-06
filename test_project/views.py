from django.http import HttpResponse
from django.shortcuts import get_object_or_404, render
from django.template import loader
from . import models
from .models import Cromo
def index(request):
	latest_cromos_list=Cromo.objects.order_by('-pub_date')
	template=loader.get_template('test_project/index.html')
	context={
		'latest_cromos_list':latest_cromos_list,
	}
	return HttpResponse(template.render(context,request))
	
def second_page(request):
	return HttpResponse("Is work, motherfuckers! :V ")

def detail(request, cromo_id):
    cromo = get_object_or_404(Cromo, pk=cromo_id)
    return render(request, 'test_project/detail.html', {'cromo': cromo})