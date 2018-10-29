
<template>
<div class = academicPage>
  <div class = "mastersClass">
    <div>
        <span class = "mastersClassText"> Master's in Computer Engineering , </span>
        <span class = "mastersClassText"> Syracuse University - New York ,</span>
        <span class = "mastersClassText"> January 2017 - December 2018 , </span>
        <span class = "mastersClassText"> Cgpa : 3.6 </span>
    </div>
    <div>
        <div class="projectTitle">
            <ul>
                <li v-for = "course in mastersCourses" v-bind:key="course">
                    <a v-on:click="courseProjects(course.courseName)">{{course.courseName}}</a>
                    <ul v-show="sublistComponentShow"> 
                        <sub-list-component v-for="sublist in course.projectsDone" :sublist="sublist" :courseName="course" :chosenCourse="chosenCourse" v-bind:key="sublist"></sub-list-component>
                    </ul>
                </li>
            </ul>
        </div>
    </div>
    <p class = "introPara"> {{introduction}} </p>
  </div>
  </div>
</template>

<script>
import subListComponent from './subListComponent'
import axios from 'axios'

export default {
  name: 'AcademicPage',
  props:['sublist','courseName' ,'chosenCourse'],
  data () {
    return {
        mastersCourses: [],
        sublistComponentShow: false,
        chosenCourse:''
      }
  },
  created () {
       axios.get(`http://localhost:3000/academic`)
      .then(response => {
        this.mastersCourses = response.data
      })
      .catch(e => {
        this.errors.push(e)
      })
  },
  methods: {
      courseProjects(courseName){
          this.sublistComponentShow = !this.sublistComponentShow;
          this.chosenCourse = courseName
      }
  },
  components: {
      subListComponent
  }
}
</script>

<style>
  .academicPage{
    overflow: auto;
    margin-left: 220px;
    margin-top: 7em;
    width:80%;
    min-height:50%;
  }
  .mastersClass{
    border-style: groove;
    margin-left: 40px;
    height: 40%;
    overflow: auto
  }

  .mastersClassText{
    font-size: 20px;
    font-family: 'Times New Roman', Times, serif;
    color:  rgb(92, 4, 4);
    text-align: left;

  }

   .projectTitle {
         font-size: 15px;
        font-family: 'Times New Roman', Times, serif;
        color:  rgb(92, 4, 4);
        text-align: left;
        text-decoration: underline;
    }
  ::-webkit-scrollbar {
    width: 10px;
    height: 15px;
  }
  ::-webkit-scrollbar-track-piece  {
    background-color:#E27D60;
  }
  ::-webkit-scrollbar-thumb:vertical {
    height: 30px;
    background-color: rgb(92, 4, 4);
  }
</style>
