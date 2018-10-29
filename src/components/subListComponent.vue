
<template>
<div>
    <li v-if="courseName.courseName === chosenCourse ">
      <a v-on:click="sublistClick(sublist)">{{sublist}} </a> </li>
</div>
</template>

<script>
export default {
  name:'subListComponent',
  props:['sublist','courseName' ,'chosenCourse'],
  methods:{
    sublistClick(sublist){
      let routeData = this.$router.resolve({name: sublist});
      window.open(routeData.href, '_blank');
    }
  }
}
</script>