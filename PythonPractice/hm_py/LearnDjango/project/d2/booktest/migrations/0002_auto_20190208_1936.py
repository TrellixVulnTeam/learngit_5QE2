# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('booktest', '0001_initial'),
    ]

    operations = [
        migrations.AlterField(
            model_name='bookinfo',
            name='comment',
            field=models.CharField(max_length=128, default=None),
        ),
        migrations.AlterField(
            model_name='bookinfo',
            name='read',
            field=models.IntegerField(default=0),
        ),
    ]
