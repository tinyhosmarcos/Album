from django.conf.urls import url

from . import views

app_name='test_project'
urlpatterns = [
    url(r'^$', views.index, name='index'),
    url(r'^second/', views.second_page, name='second_page'),
    url(r'^(?P<cromo_id>[0-9]+)/$', views.detail, name='detail'),
]